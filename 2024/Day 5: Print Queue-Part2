from collections import defaultdict, deque
from aocday5part1 import parse_combined_input
from aocday5part1 import is_update_valid


def correct_order(update, rules):
    """ordering updates acc to the rules - topological sort"""
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    elements = set(update)
    
    # graph based on the rules
    for x, y in rules:
        if x in elements and y in elements:
            graph[x].append(y)
            in_degree[y] += 1
    
    # Topological sort 
    queue = deque([node for node in elements if in_degree[node] == 0])
    sorted_order = []
    while queue:
        node = queue.popleft()
        sorted_order.append(node)
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return sorted_order

def process_updates(inp):
    rules, updates = parse_combined_input(inp)
    incorrect_updates = []
    corrected_middles = []
    
    for update in updates:
        if not is_update_valid(update, rules):
            incorrect_updates.append(update)
            corrected_update = correct_order(update, rules)
            middle = corrected_update[len(corrected_update) // 2]
            corrected_middles.append(middle)
    
    return sum(corrected_middles), incorrect_updates

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

result, incorrect_updates = process_updates(inp)

print("Sum of middle page numbers:", result)
print("Incorrect updates and their corrected orders:")
for update in incorrect_updates:
    print("Original:", update)
    print("Corrected:", correct_order(update, parse_combined_input(inp)[0]))
