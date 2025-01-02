def calc_luminance(color):
    """Calculate luminance of a color (hex format)."""
    color = color.lstrip('#')
    r, g, b = [int(color[i:i+2], 16) / 255.0 for i in (0, 2, 4)]
    r, g, b = [x / 12.92 if x <=
               0.03928 else ((x + 0.055) / 1.055) ** 2.4 for x in [r, g, b]]
    luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b
    return luminance


def choose_text_color(background_color):
    """Choose text color based on background luminance."""
    luminance = calc_luminance(background_color)
    return "#FFFFFF" if luminance < 0.5 else "#000000"


def calc_accessibility_score(text_color, background_color, images, has_keyboard_navigation, uses_aria_landmarks, uses_semantic_html):
    # Simulate contrast check (simple version)
    contrast_score = 1 if random.uniform(3, 7) >= 4.5 else 0
    # Alt text score
    alt_text_score = sum(1 for img in images if img.get(
        "alt_text")) / len(images) if images else 0
    # Other checks
    keyboard_score = 1 if has_keyboard_navigation else 0
    aria_score = 1 if uses_aria_landmarks else 0
    semantic_score = 1 if uses_semantic_html else 0

    # Calculate and return final score (average)
    return (contrast_score + alt_text_score + keyboard_score + aria_score + semantic_score) * 20
