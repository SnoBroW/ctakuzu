compile:
	@gcc *.c -g -c
	@gcc *.o -g -o main
	@echo Done!
clean:
	@rm -r *.o main vgcore.*
