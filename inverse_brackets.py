testcase = """["X","Y","."],["Y",".","."]"""


def inverse_brackets(str="", inverseQuotes=False):
    type = ''
    for x in str:
        if x == '{':
            type = '{'
            break
        elif x == '[':
            type = '['
            break

    if (type == '['):
        str = str.replace('[', '{').replace(']', "}").strip()
    if (type == '{'):
        str = str.replace('{', '[').replace('}', "]").strip()

    if inverseQuotes:
        if str.find('"') != -1:
            return str.replace('"', "'").strip()
        else:
            return str.replace("'", '"').strip()

    return str.strip()


print(inverse_brackets(
    testcase, inverseQuotes=True
))
