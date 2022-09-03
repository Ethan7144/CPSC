l = [1, 2, 3]
r = range(1, 10)
def generator(r):
    for i in r:
        yield 2 * i

def double (n):
    return n * 2

doubles = map(double, r)
for n in doubles:
    print (n)

def is_even(n):
    return n % 2 == 0

evens = filter(is_even, r)
for e in evens:
    print(e)

g = generator(l)
g

l = [1, 2, 3, 4, 6, 8, 12, 25]

def my_reducer(a,b):
    print("in reducer")
    print(a)
    print(b)
    return a + b

reduced = reduce(my_reducer, l)

reduced

reduce(my_reducer, l, 10)