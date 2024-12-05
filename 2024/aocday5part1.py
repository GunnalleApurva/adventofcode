def is_update_valid(update, rules):
    position = {page: idx for idx, page in enumerate(update)}
    
    for a, b in rules: # a comes before b
        if a in position and b in position:  
            if position[a] >= position[b]:  # Rule is violated
                return False
    return True

def find_middle(update):
    n = len(update)
    return update[n // 2] if n % 2 == 1 else update[n // 2 - 1]

def calculate_sum_of_middles(rules, updates):

    valid_middles = []
    
    for update in updates:
        if is_update_valid(update, rules):
            valid_middles.append(find_middle(update))
    
    return sum(valid_middles)

def parse_combined_input(inp):

    rules_section, updates_section = inp.strip().split("\n\n")
    
    ordering_rules = [
        tuple(map(int, line.split('|'))) for line in rules_section.splitlines()
    ]
    
    updates = [
        list(map(int, line.split(','))) for line in updates_section.splitlines()
    ]
    
    return ordering_rules, updates

#-----------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------
inp = '''47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47'''


rules, updates = parse_combined_input(inp)

# print("Rules:", rules)
# print("Updates:", updates)

result = calculate_sum_of_middles(rules, updates)
print(result)