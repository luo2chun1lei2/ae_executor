CC := clang-10
CPPC := clang++-10
LD := clang-10
OUT := ../out
TARGET := ae_executor

# -Werror 在编写代码后，进行检查时，再加入。
CC_FLAGS := -g -Wall -Wextra
C_FLAGS  := -g
LD_FLAGS := -g

SRC  := $(wildcard *.cc)
OBJS := ${patsubst %.cc,${OUT}/%.o,${SRC}}

${OUT}/%.o: %.cc
	mkdir -p ${OUT}
	${CPPC} ${CC_FLAGS} -c $< -o $@

all: ${OBJS}
	${LD} ${LD_FLAGS} $< -o ${OUT}/${TARGET}

clean:
	rm -rf ${OUT}

run:
	@${OUT}/${TARGET}
