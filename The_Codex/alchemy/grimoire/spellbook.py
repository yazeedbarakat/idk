def record_spell(spell_name: str, ingredients: str) -> str:
    from .validator import validate_ingredients
    for i in ['fire', 'water', 'earth', 'air']:
        if i in ingredients:
            return "Spell recorded: " \
                    f"{spell_name} ({validate_ingredients(ingredients)})"
    return f"Spell rejected: " \
            f"{spell_name} ({validate_ingredients(ingredients)})"
