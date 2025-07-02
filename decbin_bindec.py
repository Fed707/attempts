def int_to_binary(n):
    """Convert integer to binary (positive or negative)"""
    if n == 0:
        return "0"
    sign = "-" if n < 0 else ""
    n = abs(n)
    bits = []
    while n > 0:
        bits.append(str(n % 2))
        n //= 2
    return sign + ''.join(reversed(bits))


def frac_to_binary(fraction, precision=10):
    """Convert fractional part to binary with fixed precision"""
    bits = []
    count = 0
    while fraction > 0 and count < precision:
        fraction *= 2
        bit = int(fraction)
        bits.append(str(bit))
        fraction -= bit
        count += 1
    return ''.join(bits) if bits else "0"


def decimal_to_binary(num, precision=10):
    """Convert any number (int or float) to binary string"""
    if isinstance(num, int) or num.is_integer():
        return int_to_binary(int(num))
    
    integer_part = int(num)
    fractional_part = abs(num - integer_part)
    
    int_binary = int_to_binary(integer_part)
    frac_binary = frac_to_binary(fractional_part, precision)
    
    return f"{int_binary}.{frac_binary}"


def binary_to_decimal(binary_str):
    """Convert binary string (e.g., '101.101') to decimal number"""
    binary_str = binary_str.strip()
    if binary_str.startswith("-"):
        sign = -1
        binary_str = binary_str[1:]
    else:
        sign = 1

    if "." in binary_str:
        int_part_str, frac_part_str = binary_str.split(".")
    else:
        int_part_str, frac_part_str = binary_str, ""

    int_part = int(int_part_str, 2) if int_part_str else 0

    frac_part = 0
    for i, bit in enumerate(frac_part_str):
        if bit not in '01':
            raise ValueError("Invalid binary digit in fraction")
        frac_part += int(bit) / (2 ** (i + 1))

    return sign * (int_part + frac_part)


# === Main Program ===
if __name__ == "__main__":
    print("==== Decimal & Binary Converter ====")
    print("1. Decimal to Binary")
    print("2. Binary to Decimal")

    choice = input("Choose (1 or 2): ").strip()

    if choice == "1":
        try:
            user_input = input("Enter a decimal number (e.g. -13.625): ").strip()
            precision = int(input("Precision for binary fraction? (e.g. 10): ").strip())
            number = float(user_input)
            result = decimal_to_binary(number, precision)
            print(f"Binary: {result}")
        except ValueError:
            print("⚠️ Invalid input. Please enter a valid decimal number.")

    elif choice == "2":
        try:
            user_input = input("Enter a binary number (e.g. 1101.101): ").strip()
            result = binary_to_decimal(user_input)
            print(f"Decimal: {result}")
        except ValueError:
            print("⚠️ Invalid binary format. Only 0, 1, and one optional dot '.' are allowed.")

    else:
        print("❌ Invalid option. Please choose 1 or 2.")
