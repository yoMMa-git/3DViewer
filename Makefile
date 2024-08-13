MAKE = make
CC = g++
CFLAGS =-Wall -Werror -Wextra -Wpedantic -g -std=c++17
UI_SRC = $(wildcard ./interface/*.cpp)
UI_H = $(wildcard ./interface/*.h)
CONTROLLER_SRC = $(wildcard ./controller/*.cpp)
CONTROLLER_H = $(wildcard ./controller/*.h)
MODEL_SRC = $(wildcard ./model/*.cpp)
MODEL_H = $(wildcard ./model/*.h)
MODEL_OBJ = $(patsubst %.cpp, %.o, $(MODEL_SRC))
MODEL_OBJ_COV = $(patsubst %.cpp, %.o_cov, $(MODEL_SRC))
TEST_SRC = $(wildcard ./tests/*.cpp)
TEST_H = $(wildcard ./tests/*.h)
TEST_OBJ = $(patsubst %.cpp, %.o, $(TEST_SRC))

TEST_BUILD_DIR = build_test
CMEMTEST = valgrind --leak-check=full --track-origins=yes
# START Appears in root CMakeLists.txt
TEST_FILE = model_test
CLIB = s21_3dviewer.a
CLIB_DIR = libs
# END Appears in root CMakeLists.txt

QMAKE = qmake
CMAKE = cmake
OUTPUT_DIR = 3DViewer_v2.0
APP_LABEL = 3DViewer_v2
APP_OUTPUT_QMAKE = interface/3DViewer_v2
APP_OUTPUT_CMAKE = interface/3DViewer_v2
FONT_DIR = ~/.local/share/fonts/
OPENER = xdg-open

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
APP_OUTPUT_QMAKE = interface/3DViewer_v2.app/Contents/MacOS/3DViewer_v2
APP_OUTPUT_CMAKE = interface/3DViewer_v2.app/Contents/MacOS/3DViewer_v2
FONT_DIR = ~/Library/Fonts/
OPENER = open
CMEMTEST = leaks -atExit --
endif

.PHONY: all install qmake_install cmake_install run uninstall dist dvi dv_rus gcov_report test style memtest memtest_app clean dist_clean libs rebuild s21_3dviewer_model.a s21_3dviewer_model.a_cov style_fix font

# Main targets

all: install run

install:
	$(MAKE) qmake_install
	@echo -e '\033[32mInstallation is done!\033[0m'

reinstall: clean uninstall install
	@echo -e '\033[32mSuccessfully reinstalled!\033[0m'

qmake_install: font
	cd interface && $(QMAKE) && $(MAKE)
	mkdir -p $(OUTPUT_DIR)
	unzip -o misc/models.zip -d $(OUTPUT_DIR)/
	mv $(APP_OUTPUT_QMAKE) $(OUTPUT_DIR)/

run:
	./$(OUTPUT_DIR)/$(APP_LABEL)

uninstall:
	rm -rf ./$(OUTPUT_DIR)

dist: clean distclean
	tar -cf 3DViewer_v2.0.tar interface model controller misc tests CMakeLists.txt Makefile README.md README_RUS.md

dvi:
	$(OPENER) README.md

dvi_rus:
	$(OPENER) README_RUS.md

gcov_report: test
	lcov -t "3DViewer_v2" -o s21_3dviewer.info -c -d ./model/ --no-external
	genhtml -o report s21_3dviewer.info
	$(OPENER) ./report/index.html

test: s21_3dviewer.a_cov
	unzip -o misc/test_files.zip -d tests/
	$(CMAKE) -S . -B $(TEST_BUILD_DIR)
	$(CMAKE) --build $(TEST_BUILD_DIR)
	mv ./$(TEST_BUILD_DIR)/$(TEST_FILE) ./
	./$(TEST_FILE)

style: clean
	clang-format -style=Google -n $(MODEL_SRC) $(MODEL_H) $(TEST_SRC) $(TEST_H) $(UI_SRC) $(CONTROLLER_SRC)

memtest: clean test
	$(CMEMTEST) ./$(TEST_FILE)

memtest_app: install
	$(CMEMTEST) ./$(OUTPUT_DIR)/$(APP_LABEL)

clean:
	rm -rf $(TEST_FILE)
	rm -f ./*.o ./*.o_cov ./tests/*.o ./*.a ./model/*.o_cov ./model/*.o
	rm -rf ./*.gcda ./*.gcno ./*.info ./model/*.gcda ./model/*.gcno ./model/*.info
	rm -rf ./report/
	rm -rf ./$(TEST_BUILD_DIR)
	rm -rf ./$(CLIB_DIR)
	rm -rf interface/.qmake.stash interface/Makefile interface/moc_*
	rm -rf interface/ui_*.h interface/*.o interface/$(APP_LABEL).app interface/qrc_resource.cpp
	rm -rf interface/$(APP_LABEL)_autogen interface/CMakeFiles interface/*.cmake interface/*Cache.txt

distclean:
	rm -rf 3DViewer_v2.0.tar

rebuild: clean all

# Misc targets

libs: s21_3dviewer.a

s21_3dviewer.a: $(MODEL_OBJ)
	rm -rf $(CLIB_DIR)/$(CLIB)
	mkdir -p $(CLIB_DIR)
	ar -rs $(CLIB_DIR)/$(CLIB) $(MODEL_OBJ)

s21_3dviewer.a_cov: $(MODEL_OBJ_COV)
	rm -rf $(CLIB_DIR)/$(CLIB)
	mkdir -p $(CLIB_DIR)
	ar -rs $(CLIB_DIR)/$(CLIB) $(MODEL_OBJ_COV)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o_cov: %.cpp
	$(CC) $(CFLAGS) -O0 --coverage -c $< -o $@

font:
	mkdir -p $(FONT_DIR)
	cp misc/fonts/Anta-Regular.ttf $(FONT_DIR)
ifeq ($(UNAME_S), Linux)
	fc-cache -fv $(FONT_DIR)
endif

style_fix: clean
	clang-format -style=Google -i $(MODEL_SRC) $(MODEL_H) $(TEST_SRC) $(TEST_H) $(UI_SRC) $(UI_H) $(CONTROLLER_SRC) $(CONTROLLER_H)
