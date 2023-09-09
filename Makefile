default:
	gcc -o llist -g main.c dll.c node.c

test:
	gcc -o llist -g node.c dll.c main.c

compile_headers:
	gcc -o llist -g node.c node.h dll.c dll.h main.c

clean:
	rm llist
