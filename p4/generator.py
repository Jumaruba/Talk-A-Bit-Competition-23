import random 


def generate_random_number(begin, end):
    return random.randint(begin, end)

test_cases = generate_random_number(1, 20)
print(test_cases)
for i in range(test_cases):
    routes = generate_random_number(2, 20000)
    print(routes)
    for j in range(routes):
        print(generate_random_number(-100, 100), generate_random_number(-100, 100))