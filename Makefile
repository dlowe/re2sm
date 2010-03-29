all: re2sm

CC=gcc
CFLAGS=-ggdb -Wall -Werror -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wstrict-prototypes -Wredundant-decls -Wnested-externs -Winline -Wunused
LFLAGS=-L/usr/local/lib
DATE=`date -u "+%a %h %d %T 20%y"`

all: count re2sm ioccc.entry re2sm-preprocessed
other: re2sm-indented re2sm-preprocessed-indented

re2sm-indented:
	@echo "Building re2sm.c.indented"
	@indent re2sm.c re2sm.c.indented

re2sm-preprocessed:
	@echo "Building re2sm.c.preprocessed"
	@${CC} -E ${CFLAGS} -o re2sm.c.preprocessed re2sm.c

re2sm-preprocessed-indented: re2sm-preprocessed
	@echo "Building re2sm.c.preprocessed.indented"
	@indent re2sm.c.preprocessed re2sm.c.preprocessed.indented

ioccc.entry: re2sm.c remark build author entry testcf.sh
	@echo "Building ioccc.entry"
	@( echo "---entry---"; \
	   cat entry; \
	   echo "---remark---"; \
	   cat remark; \
	   echo "---author---"; \
	   cat author; \
       echo "---info---"; \
       uuencode testcf.sh < testcf.sh; \
	   echo "---build---"; \
	   uuencode build < build; \
	   echo "---program---"; \
	   uuencode prog.c < re2sm.c; \
           echo "---end---" ) \
	| sed -e '/^begin 6/ s/6/4/' \
              -e "s/__DATE__/${DATE}/"  > ioccc.entry

re2sm: re2sm.o
	${CC} -o re2sm re2sm.o ${LFLAGS}

count:
	@( \
		SIZE=`wc -c re2sm.c | awk '{print $$1}'`; \
		COUNTEDSIZE=`./count.pl re2sm.c`; \
		if [ "$${COUNTEDSIZE}" -gt "2048" ]; then \
			echo "** WARNING: Over charcount limit! **"; \
		fi; \
		echo "Counted size is $${COUNTEDSIZE} / 2048"; \
		if [ "$${SIZE}" -gt "4096" ]; then \
			echo "** WARNING: Over size limit **"; \
		fi; \
		echo "Actual size is $${SIZE} / 4096" \
	 )

clean:
	@rm -f ioccc.entry re2sm re2sm.o a.out *.core re2sm.c.preprocessed re2sm.c.indented re2sm.c.preprocessed.indented compress.out
