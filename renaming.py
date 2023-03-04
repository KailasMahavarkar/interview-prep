import os

name = "28. Find the Index of the First Occurrence in a String"


obsidian = False
obsidian_path = "E:\onedrive\obsidian"
cpp_path = os.path.join(obsidian_path, 'cpp')
leetcode_path = os.path.join(cpp_path, 'leetcode')

if not obsidian_path:
    print("Obsidian Path does not exist")
    exit(1)

if not leetcode_path:
    # create path
    os.mkdir(cpp_path)
    os.mkdir(leetcode_path)


parts = name.split('.')
p1 = "_leetcode_" + parts[0]
p2 = parts[1].lower().replace(" ", '_').replace("|", "").replace("__", "_")

if obsidian:
    folder = p2 + p1
    if (folder.startswith("_")):
        folder = folder[1:]
        canvas_name = "canvas_" + folder + ".excalidraw"
        note_name = "note_" + folder

        problem_path = os.path.join(leetcode_path, folder)

        canvas_path = os.path.join(problem_path, canvas_name)
        note_path = os.path.join(problem_path, note_name)

        if not os.path.exists(problem_path):
            os.mkdir(os.path.join(problem_path))

        # copy content from "excalidraw.md" to new file to canvas_path
        if not os.path.exists(canvas_path):

            # create a local copy of file "excalidraw.md" using os module
            # rename it and move it to location canvas_path

            with open(canvas_path, 'w') as f:
                f.write("")

        # create note
        if not os.path.exists(note_path):
            with open(note_path, 'w') as f:
                f.write("")


t1 = p2 + p1 + '.py'
t2 = p2 + p1 + '.cpp'
t3 = p2 + p1 + '.js'


if (t1.startswith("_")):
    print(t1[1:])

if (t2.startswith("_")):
    print(t2[1:])

if (t3.startswith("_")):
    print(t3[1:])
    print(t3[1:][:-3])
    print(t3[1:][:-3] + ".excalidraw")

