run:
	./app

build:
	@gcc -o app main.c

exec:
	$(MAKE) build
	$(MAKE) run
