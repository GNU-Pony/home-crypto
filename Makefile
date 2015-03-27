# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.


PREFIX = /usr
BIN = /bin
DATA = /share
LICENSES = /licenses
INFO = /info
BINDIR = $(PREFIX)$(BIN)
DATADIR = $(PREFIX)$(DATA)
LICENSEDIR = $(DATADIR)$(LICENSES)
INFODIR = $(DATADIR)$(INFO)
SYSCONFDIR = /etc

PKGNAME = home-crypto


OPTIMISE = -Og -g

STD = gnu99

WARN = -Wall -Wextra -Wdouble-promotion -Wformat=2 -Winit-self -Wmissing-include-dirs            \
       -Wtrampolines -Wfloat-equal -Wshadow -Wmissing-prototypes -Wmissing-declarations          \
       -Wredundant-decls -Wnested-externs -Winline -Wno-variadic-macros -Wsync-nand              \
       -Wunsafe-loop-optimizations -Wcast-align -Wstrict-overflow -Wdeclaration-after-statement  \
       -Wundef -Wbad-function-cast -Wcast-qual -Wwrite-strings -Wlogical-op -Waggregate-return   \
       -Wstrict-prototypes -Wold-style-definition -Wpacked -Wvector-operation-performance        \
       -Wunsuffixed-float-constants -Wsuggest-attribute=const -Wsuggest-attribute=noreturn       \
       -Wsuggest-attribute=pure -Wsuggest-attribute=format -Wnormalized=nfkc -Wconversion        \
       -fstrict-aliasing -fstrict-overflow -fipa-pure-const -ftree-vrp -fstack-usage             \
       -funsafe-loop-optimizations -pedantic

DEFS = SYSCONFDIR PKGNAME

FLAGS = $(OPTIMISE) -std=$(STD) $(WARN) $(foreach D,$(DEFS),-D'$(D)="$($(D))"')

CC_FLAGS = $(FLAGS) $(CPPFLAGS) $(CFLAGS)
LD_FLAGS = $(FLAGS) $(LDFLAGS)


OBJ = home-crypto



.PHONY: default
default: command

.PHONY: all
all: command

.PHONY: command
command: home-crypto


.PHONY: home-crypto
home-crypto: bin/home-crypto

bin/home-crypto: $(foreach O,$(OBJ),obj/$(O).o)
	@mkdir -p bin
	$(CC) $(LD_FLAGS) -o "$@" $^

obj/%.o: src/%.c src/*.h
	@mkdir -p obj
	$(CC) $(CC_FLAGS) -o "$@" -c "$<"


.PHONY: clean
clean:
	-rm -r bin obj

