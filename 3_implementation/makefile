PROJ_NAME = student_management_system

TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = ./Build

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif 

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

SRC : src/Add_Student.c src/search_student.c src/search_student_course.c src/view_student_details.c src/remove_student.c src/update.c

INC =  -Iinc\
-Iunity

UNITY = unity/unity.c 

test_src = test_files/check_name.c 

all:$(BUILD_DIR)
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))


run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	gcov -a main.c $(SRC) $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(RM) *.gcno
	$(RM) *.gcov
	$(RM) *.gcda

test: $(SRC) $(test_src) $(UNITY)
	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

	
valgrind:
	valgrind $(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcno
	$(RM) *.gcov
	$(RM) *.gcda
	$(RM) *.bin