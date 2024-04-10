import re

def find_numbers(input_file, output_file):
    # Открываем файл для чтения
    with open(input_file, 'r') as file:
        data = file.read()

    # Используем регулярное выражение для поиска чисел перед ":"
    numbers = re.findall(r'\b\d+(?=:)', data)

    # Объединяем последовательные числа через "-"
    merged_numbers = []
    start_number = None
    for num in numbers:
        num = int(num)
        if start_number is None:
            start_number = num
        elif num == start_number + 1:
            start_number = num
        else:
            if len(merged_numbers) > 0:
                merged_numbers.append(f"-{start_number}")
            merged_numbers.append(str(num))
            start_number = num

    if start_number is not None:
        merged_numbers.append(f"-{start_number}")

    # Убираем пробелы между числом и "-"
    merged_numbers_str = ' '.join(merged_numbers)
    merged_numbers_str = merged_numbers_str.replace(' -', '-')
    
    # Записываем найденные числа в файл
    with open(output_file, 'w') as file:
        file.write(merged_numbers_str)

# Пример использования функции
find_numbers('input.txt', 'output.txt')
