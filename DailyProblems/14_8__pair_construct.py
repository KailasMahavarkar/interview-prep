def const(a, b):
    # pair accepts function only
    def pair(f):
        return f(a, b)
    return pair

# arg -> pair | uncalled <when called> pair(f) -> f(a, b)

def car(pair):
    def inner(a, b):
        return a
    return pair(inner)

def cdr(pair):
    def inner(a, b):
        return b
    return pair(inner)

print(car(const(3, 4)))
print(cdr(const(3, 4)))