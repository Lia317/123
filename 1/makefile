all: fio test check

fio: main.c
	gcc -o fio main.c

test: test.c
	gcc -o test test.c

check: out test
	./test < ./fio_out > ./check_result

out: fio
	./fio > ./fio_out

debug: debug_fio debug_test debug_check

debug_fio:
	gcc -g -o fio_debug main.c

debug_test:
	gcc -g -o test_debug test.c

debug_out: debug_fio
	./fio_debug > ./fio_debug_out

debug_check: debug_out debug_test
	./test_debug < ./fio_debug_out > ./check_result_debug

clean:
	rm -f fio fio_debug fio_out fio_debug_out test test_debug check_result check_result_debug
