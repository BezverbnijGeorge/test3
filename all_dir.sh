

#!/bin/bash

# Зберігаємо ім'я файлу в змінній
filename="$1"

dir="$2"

# Функція для рекурсивного обходу директорій
traverse_directory() {
  # Виконуємо команду ls | grep "^$filename$" і перевіряємо, чи не пустий результат
  if [ -n "$(ls | grep "^$filename$")" ]; then
    # Якщо результат не пустий, виводимо повідомлення і результат
    echo "Current directory: $(pwd)"
    echo "File was found:"
    ls | grep "^$filename$"
  fi
  

  # Перебираємо всі файли і директорії в поточній директорії
  for file in *; do
    # Перевіряємо, чи є це директорія
    if [ -d "$file" ]; then
      # Якщо так, рекурсивно обходимо її
      
      cd "$file"
      #traverse_directory
      exec "/home/schmjul/labs/unix/6lab/all_dir.sh" "$filename" "$file" "0" 
      echo "Current directory: $(pwd)"
      cd ..
      
    fi
  done
}

# Викликаємо функцію, починаючи з поточної директорії


if [ "$3" -eq 1 ]; then
  cd "$dir"
fi


#cd ..
traverse_directory
