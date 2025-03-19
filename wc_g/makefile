# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS =

# Исходные файлы
SRCS = main.c dict.c parser.c

# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Имя исполняемого файла
TARGET = word_count

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Правило для компиляции .c файлов в .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)

# Псевдоцель для предотвращения конфликтов с файлами
.PHONY: all clean
