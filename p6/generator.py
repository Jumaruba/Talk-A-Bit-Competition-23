import random 


def generate_random_number(begin, end):
    return random.randint(begin, end)

for j in range(4,18):
    size = generate_random_number(1, 30000)//2+1
    ans = generate_random_number(-30000, 30000)
    arr = []
    s = set([])
    for i in range(size):
        rand_number = generate_random_number(-30000, 30000)
        while(rand_number == ans or rand_number in s):
            rand_number = generate_random_number(-30000, 30000)
        arr.append(rand_number)
        arr.append(rand_number)
        s.add(rand_number)

    arr.append(ans)
    random.shuffle(arr)
    input = " ".join(map(str, arr))

    fi = open(f"./input/input{str(j)}.txt", "w")
    fo = open(f"./output/output{str(j)}.txt", "w")
    fi.write(str(size*2+1) + "\n")
    fi.write(input)
    fo.write(str(ans) + "\n")



