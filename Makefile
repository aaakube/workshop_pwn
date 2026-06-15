slides.pdf: slides.md style.tex
	pandoc \
		-t beamer \
		--slide-level 2 \
		--pdf-engine xelatex \
		slides.md -o slides.pdf

.PHONY: clean
clean:
	rm -f slides.pdf
