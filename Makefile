run:
	./prog

build:
	gcc sqlite3.c main.c -o prog

exec:
	$(MAKE) build
	$(MAKE) run
