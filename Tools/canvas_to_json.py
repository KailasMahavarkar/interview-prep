import json
import pyperclip

canvas = {
    "nodes": [
        {"id": "96cdce3f3bba8da5", "type": "text", "text": "56. Merge Intervals",
            "x": -240, "y": -280, "width": 250, "height": 60, "color": "2"},
        {"id": "0703cc490d826f20", "type": "text", "text": "57. Insert Interval",
         "x": -240, "y": -180, "width": 250, "height": 60, "color": "2"},
        {"id": "a21a8557c0129324", "type": "text", "text": "435. Non-Overlapping Intervals",
         "x": -240, "y": -80, "width": 250, "height": 60, "color": "2"},
        {"id": "52cb06a95202dc34", "type": "text", "text": "986. Interval List Intersections",
         "x": -240, "y": 20, "width": 250, "height": 60, "color": "2"},
        {"id": "711b4da8dd703477", "type": "text", "text": "1288. Remove Covered Intervals",
         "x": -240, "y": 120, "width": 250, "height": 68, "color": "2"},
        {"id": "54acdffac1ce8d2d", "type": "text", "text": "1229. Meeting Scheduler",
         "x": -240, "y": 230, "width": 250, "height": 60, "color": "2"},
        {"id": "b8858b42a585dfe2", "type": "text", "text": "252. Meeting Rooms",
         "x": -560, "y": -280, "width": 250, "height": 60, "color": "4"},
        {"id": "2a183a6212d7ef26", "type": "text", "text": "253. Meeting Rooms II",
         "x": 140, "y": -280, "width": 250, "height": 60, "color": "1"},
        {"id": "f255b30f51ca1b18", "type": "text", "text": "715. Range Module",
         "x": 140, "y": -174, "width": 250, "height": 60, "color": "1"},
        {"id": "d00f4abb668bb4f2", "type": "text", "text": "759. Employee Free Time",
         "x": 140, "y": -80, "width": 250, "height": 60, "color": "1"},
        {"id": "373c2ac24d6a9a7e", "type": "text", "text": "Interval Based Questions",
         "x": -240, "y": -480, "width": 250, "height": 60, "color": "6"}
    ],
    "edges": [
        {"id": "0574c68df127d3a4", "fromNode": "373c2ac24d6a9a7e",
            "fromSide": "bottom", "toNode": "b8858b42a585dfe2", "toSide": "top"},
        {"id": "f33ddfea2dc696d8", "fromNode": "373c2ac24d6a9a7e",
         "fromSide": "bottom", "toNode": "96cdce3f3bba8da5", "toSide": "top"},
        {"id": "c66da7d05ffca4b4", "fromNode": "373c2ac24d6a9a7e",
         "fromSide": "bottom", "toNode": "2a183a6212d7ef26", "toSide": "top"},
        {"id": "b8cc66f0157bec02", "fromNode": "96cdce3f3bba8da5",
         "fromSide": "bottom", "toNode": "0703cc490d826f20", "toSide": "top"},
        {"id": "278c1c16a30ffc5d", "fromNode": "0703cc490d826f20",
         "fromSide": "bottom", "toNode": "a21a8557c0129324", "toSide": "top"},
        {"id": "046cf6bc07723339", "fromNode": "a21a8557c0129324",
         "fromSide": "bottom", "toNode": "52cb06a95202dc34", "toSide": "top"},
        {"id": "0c69d75dec44b1d7", "fromNode": "52cb06a95202dc34",
         "fromSide": "bottom", "toNode": "711b4da8dd703477", "toSide": "top"},
        {"id": "19305fea09411ba4", "fromNode": "711b4da8dd703477",
         "fromSide": "bottom", "toNode": "54acdffac1ce8d2d", "toSide": "top"},
        {"id": "6160e7e4f996bb5b", "fromNode": "2a183a6212d7ef26",
         "fromSide": "bottom", "toNode": "f255b30f51ca1b18", "toSide": "top"},
        {"id": "572f8d4c054b4390", "fromNode": "f255b30f51ca1b18",
         "fromSide": "bottom", "toNode": "d00f4abb668bb4f2", "toSide": "top"}
    ]
}


def question_to_link(str):
    if len(str.split(".")) != 2:
        return str

    problem_number = str.split(".")[0]
    question = str.split(".")[1]

    dynamic = question.replace(' ', '-').lower()
    if dynamic[0] == '-':
        dynamic = dynamic[1:]

    link = f"https://leetcode.com/problems/{dynamic}/description/"
    return link


# Iterate over the nodes and convert the text into the desired format
for node in canvas["nodes"]:
    question = node["text"]
    link = question_to_link(question)
    node["text"] = f"[{question}]({link})"

# print(json.dumps(canvas, indent=2))

pyperclip.copy(json.dumps(canvas, indent=2))
