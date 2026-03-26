def validate_ingredients(ingredients: str) -> str:
    for i in ['fire', 'water', 'earth', 'air']:
        if i in ingredients:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
