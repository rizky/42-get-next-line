p ((t_file*)(file)->content)->content

>>>> Tests for get_next_line
Source: github.com/yyang42/moulitest
Legend: (.) Ok / (F) Fail / (S) Segfault / (B) Bus error / (T) Timeout / (A) Abort

[ -------STARTING ALL UNIT TESTS------- ]
>>>> 01_test_simple.spec.c ------- [Ok !] .
>>>> 02_test_eof_with_close.spec.c [Ok !] .
>>>> 03_test_medium_string.spec.c  [Ok !] .
>>>> 04_test_return_values.spec.c  [FAIL] S [SEGV] simple_string -> (null)
>>>> 05_test_error_handling.spec.c [FAIL] F [FAIL] simple_string -> get_next_line(-99, ((void*)0)) == -1
>>>> 06_test_line_of_08.spec.c --- [Ok !] .
>>>> 07_test_two_lines_of_08.spec. [FAIL] S [SEGV] simple_string -> (null)
>>>> 08_test_few_lines_of_08.spec. [FAIL] F [FAIL] simple_string -> strcmp(line, "abcdefgh") == 0
>>>> 09_test_line_of_16.spec.c --- [Ok !] .
>>>> 10_test_two_lines_of_16.spec. [Ok !] .
>>>> 11_test_few_lines_of_16.spec. [Ok !] .
>>>> 12_test_line_of_4.spec.c ---- [FAIL] S [SEGV] simple_string -> (null)
>>>> 13_test_two_lines_of_4.spec.c [FAIL] F [FAIL] simple_string -> strcmp(line, "abcd") == 0
>>>> 14_test_few_lines_of_4.spec.c [Ok !] .
>>>> 15_test_line_without_nl.spec. [Ok !] .
>>>> 16_test_line_of_8_without_nl. [Ok !] .
>>>> 17_test_line_of_16_without_nl [Ok !] .
>>>> 30_bonus_multiple_fd.spec.c - [FAIL] S [SEGV] simple_string -> strcmp(line_fd0, "aaa") == 0
>>>> 40_hard_test_medium_string.sp [Ok !] .
>>>> 41_hard_test_large_file.spec. [FAIL] T [TIME] test01 -> (null)
>>>> 42_hard_test_one_big_fat_line [FAIL] S [SEGV] test01 -> (null)
[ ----------END OF UNIT TESTS---------- ]

>>>> Result: 12/21 test suites passed. 12/21 tests passed (dots).

Check if buff = 0
and check if line == NULL;