click_mouse: mkdir
	gcc -o ./build/mouse_click ./src/main.c -framework ApplicationServices

mkdir: clean
	mkdir build

clean:
	rm -rf ./build
