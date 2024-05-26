# ansi_colors.py

class AnsiColors:
    RESET = '\33[0m'
    BOLD = '\33[1m'
    ITALIC = '\33[3m'
    UNDERLINE = '\33[4m'
    BLINK = '\33[5m'
    BLINK2 = '\33[6m'
    SELECTED = '\33[7m'

    BLACK = '\33[30m'
    RED = '\33[31m'
    GREEN = '\33[32m'
    YELLOW = '\33[33m'
    BLUE = '\33[34m'
    VIOLET = '\33[35m'
    BEIGE = '\33[36m'
    WHITE = '\33[37m'

    BLACK_BG = '\33[40m'
    RED_BG = '\33[41m'
    GREEN_BG = '\33[42m'
    YELLOW_BG = '\33[43m'
    BLUE_BG = '\33[44m'
    VIOLET_BG = '\33[45m'
    BEIGE_BG = '\33[46m'
    WHITE_BG = '\33[47m'

    GREY = '\33[90m'
    BRIGHT_RED = '\33[91m'
    BRIGHT_GREEN = '\33[92m'
    BRIGHT_YELLOW = '\33[93m'
    BRIGHT_BLUE = '\33[94m'
    BRIGHT_VIOLET = '\33[95m'
    BRIGHT_BEIGE = '\33[96m'
    BRIGHT_WHITE = '\33[97m'

    GREY_BG = '\33[100m'
    BRIGHT_RED_BG = '\33[101m'
    BRIGHT_GREEN_BG = '\33[102m'
    BRIGHT_YELLOW_BG = '\33[103m'
    BRIGHT_BLUE_BG = '\33[104m'
    BRIGHT_VIOLET_BG = '\33[105m'
    BRIGHT_BEIGE_BG = '\33[106m'
    BRIGHT_WHITE_BG = '\33[107m'


# level 1 -> red
# level 2 -> green
# level 3 -> yellow
# level 4 -> blue
# level 5 -> violet
# level 6 -> beige
# level 7 -> white
# level 8 -> grey
# level 9 -> bright red
# level 10 -> bright green
# level 11 -> bright yellow
# level 12 -> bright blue

def pprint(level=0, *args):
    if type(level) != int:
        print(level)
        return

    if level == 0:
        print(f"{' '.join(map(str, args))}")
    elif level == 1:
        print(f"{AnsiColors.RED}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 2:
        print(f"{AnsiColors.GREEN}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 3:
        print(f"{AnsiColors.YELLOW}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 4:
        print(f"{AnsiColors.BLUE}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 5:
        print(f"{AnsiColors.VIOLET}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 6:
        print(f"{AnsiColors.BEIGE}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 7:
        print(f"{AnsiColors.WHITE}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 8:
        print(f"{AnsiColors.GREY}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 9:
        print(f"{AnsiColors.BRIGHT_RED}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 10:
        print(f"{AnsiColors.BRIGHT_GREEN}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 11:
        print(f"{AnsiColors.BRIGHT_YELLOW}{' '.join(map(str, args))}{AnsiColors.RESET}")
    elif level == 12:
        print(f"{AnsiColors.BRIGHT_BLUE}{' '.join(map(str, args))}{AnsiColors.RESET}")
    else:
        print(f"{AnsiColors.WHITE}{' '.join(map(str, args))}{AnsiColors.RESET}")