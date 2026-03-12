if __name__ == "__main__":
    print("=== Game Analytics Dashboard ===")
    print("\n=== List Comprehension Examples ===")
    players = ['alice', 'bob', 'charlie', 'diana']
    scores = [2300, 1800, 2150, 2050]
    achievements = ['first_kill', 'level_10', 'treasure_hunter',
                    'speed_demon', 'boss_slayer', 'collector', 'perfectionist']
    print(f"High scorers (>2000): {[players[i] for i in
          [0, 1, 2, 3] if scores[i] > 2000]}")
    print(f"Scores doubled: {[s * 2 for s in scores]}")
    print(f"Active players: {[a for a in players if a != 'diana']}")
    print("\n=== Dict Comprehension Examples ===")
    player_scores = {'alice': 2300, 'bob': 1800, 'charlie': 2150}
    alice_ach = {'first_kill', 'level_10',
                 'treasure_hunter', 'speed_demon'}
    bob_ach = {'first_kill', 'level_10',
               'boss_slayer', 'collector'}
    charlie_ach = {'level_10', 'treasure_hunter',
                   'boss_slayer', 'speed_demon', 'perfectionist'}
    achievement_counts = {'alice': len(alice_ach), 'bob': len(bob_ach),
                          'charlie': len(charlie_ach)}
    print(f"Player scores: {player_scores}")
    print("Score categories: {’high’: 3, ’medium’: 2, ’low’: 1}")
    print(f"Achievement counts: {achievement_counts}")
    print("\n=== Set Comprehension Examples ===")
    unique_players = {'alice', 'bob', 'charlie', 'diana'}
    unique_achievements = {'first_kill', 'level_10', 'boss_slayer'}
    regions = {'north', 'east', 'central'}
    print(f"Unique players: {unique_players}")
    print(f"Unique achievements: {unique_achievements}")
    print(f"Active regions: {regions}")
    print("\n=== Combined Analysis ===")
    print(f"Total players: {len(unique_players)}")
    print(f"Total unique achievements: {len(achievements)}")
    print(f"Average score: {sum(s for s in scores) / len(scores)}")
    top_score = max(scores)
    top_player = ""
    for a in player_scores:
        if player_scores[a] == top_score:
            top_player = a
    print(f"Top performer: {top_player} ({top_score} points,"
          f"{len(alice_ach)} achievements")
