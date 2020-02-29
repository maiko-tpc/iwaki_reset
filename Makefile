all: iwaki_reset
	gcc -lm -o iwaki_reset iwaki_reset.c

clean:
	rm -f iwaki_reset
