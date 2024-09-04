build:
	@if [ ! -d dist ]; then mkdir dist; fi
	@gcc src/main.c -o dist/main

run:
	@dist/main

clean:
	@rm -r dist

exec: build run

