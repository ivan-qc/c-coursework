#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is the number of voters who prefer candidate i over candidate j
int preferences[MAX][MAX] = {0};

// locked[i][j] indicates if candidate i is locked in over candidate j
bool locked[MAX][MAX] = {false};

// tracks if a node has been visited during cycle detection
bool visited_node[MAX] = {false};

// Struct to represent a pair of candidates (winner and loser)
typedef struct
{
    int winner; // Index of the winning candidate
    int loser;  // Index of the losing candidate
} pair;

// Array of candidate names
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // Array to store pairs of candidates

int pair_count; // Total number of pairs
int candidate_count; // Total number of candidates

// Function prototypes
bool cycle_check(int start, int end); // Checks for cycles in the graph
bool vote(int rank, string name, int ranks[]); // Records a voter's preference
void record_preferences(int ranks[]); // Updates preferences based on votes
void add_pairs(void); // Creates pairs based on preferences
void sort_pairs(void); // Sorts pairs in order of strength of victory
void lock_pairs(void); // Locks pairs into the graph while avoiding cycles
void print_winner(void); // Determines and prints the winner of the election

int main(int argc, string argv[])
{
    // Check for invalid usage: at least one candidate must be provided
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1; // Exit with error code
    }

    // Populate array of candidates
    candidate_count = argc - 1; // Number of candidates is the number of command-line arguments minus 1
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2; // Exit with error code
    }
    
    // Copy candidate names from command-line arguments
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Initialize the graph of locked pairs to false
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0; // Initialize pair count
    int voter_count = get_int("Number of voters: "); // Get the number of voters

    // Collect votes from each voter
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count]; // Array to hold the ranks for the current voter

        // Query for each rank of the current voter
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1); // Get the candidate's name for this rank

            // Validate the vote; if invalid, exit with error code
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3; // Exit with error code
            }
        }

        record_preferences(ranks); // Update preferences based on the voter's ranks

        printf("\n"); // Print a newline for clarity
    }

    add_pairs(); // Create pairs of candidates based on preferences
    sort_pairs(); // Sort pairs by strength of victory
    lock_pairs(); // Lock pairs into the candidate graph
    print_winner(); // Print the winner of the election
    return 0; // Successful execution
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Check if the candidate name matches any candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0) // Compare names
        {
            ranks[rank] = i; // Store the index of the candidate
            return true; // Valid vote
        }
    }
    return false; // Invalid vote
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Update preferences matrix based on ranks given by the voter
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++; // Increment preference for i over j
        }
    }
    return; // End of function
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Create pairs based on preferences
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Check which candidate is preferred
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i; // i wins over j
                pairs[pair_count].loser = j;
                pair_count++; // Increment pair count
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j; // j wins over i
                pairs[pair_count].loser = i;
                pair_count++; // Increment pair count
            }
        }
    }
    return; // End of function
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Simple bubble sort to arrange pairs based on strength of victory
    pair backup; // Temporary variable for swapping pairs
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            // Compare strength of victory between pairs
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                // Swap pairs if the current pair has less strength
                backup = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = backup;
            }
        }
    }
    return; // End of function
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Clear visited nodes for cycle detection
    for (int i = 0; i < candidate_count; i++)
    {
        visited_node[i] = false;
    }

    // Lock pairs while checking for cycles
    for (int i = 0; i < pair_count; i++)
    {
        // Only lock the pair if it doesn't create a cycle
        if (!cycle_check(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true; // Lock the pair
        }
    }
    return; // End of function
}

// Print the winner of the election
void print_winner(void)
{
    // Determine the winner based on locked pairs
    int winner_index = -1; // Initialize winner index
    bool aimed; // Flag to track if a candidate is aimed at by others

    for (int i = 0; i < candidate_count; i++)
    {
        aimed = false; // Reset aimed flag for each candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // If any candidate has locked in a pair aimed at i, set aimed to true
            if (locked[j][i] == true)
            {
                aimed = true;
                break; // No need to check further
            }
        }
        // If no candidate is aimed at i, then i is the winner
        if (aimed == false)
        {
            winner_index = i;
        }
    }

    if (winner_index != -1)
    {
        printf("%s\n", candidates[winner_index]); // Print the winner's name
    }
    return; // End of function
}

// Cycle detection using DFS
bool cycle_check(int start, int end)
{
    // Base case: if start equals end, a cycle is detected
    if (start == end)
    {
        return true;
    }

    // Mark the current node as visited
    visited_node[start] = true;

    // Recursive call to check for cycles in the graph
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[start][i] == true) // If there is a lock from start to i
        {
            if (cycle_check(i, end)) // Recursive cycle check
            {
                return true; // Cycle detected
            }
        }
    }
    visited_node[start] = false; // Unmark the node before returning
    return false; // No cycle found
}
