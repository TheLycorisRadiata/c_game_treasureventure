#include "../headers/lexicon.h"

/* Declared as extern in ../headers/lexicon.h */
char list_lexicon[NBR_WORDS][LENGTH_WORD];

void populate_list_lexicon(void)
{
    memset(list_lexicon, 0, NBR_WORDS * LENGTH_WORD * sizeof(char));

    memcpy(LEXICON_1, "1", LENGTH_WORD);
    memcpy(LEXICON_2, "2", LENGTH_WORD);
    memcpy(LEXICON_3, "3", LENGTH_WORD);
    memcpy(LEXICON_AROUND, "around", LENGTH_WORD);
    memcpy(LEXICON_BACK, "back", LENGTH_WORD);
    memcpy(LEXICON_BOOK, "book", LENGTH_WORD);
    memcpy(LEXICON_BOOKS, "books", LENGTH_WORD);
    memcpy(LEXICON_CLOCK, "clock", LENGTH_WORD);
    memcpy(LEXICON_DOOR, "door", LENGTH_WORD);
    memcpy(LEXICON_DOORS, "doors", LENGTH_WORD);
    memcpy(LEXICON_DOUBLE, "double", LENGTH_WORD);
    memcpy(LEXICON_DROP, "drop", LENGTH_WORD);
    memcpy(LEXICON_ENTRY, "entry", LENGTH_WORD);
    memcpy(LEXICON_FIRST, "first", LENGTH_WORD);
    memcpy(LEXICON_GO, "go", LENGTH_WORD);
    memcpy(LEXICON_GRANDFATHER, "grandfather", LENGTH_WORD);
    memcpy(LEXICON_HALLWAY, "hallway", LENGTH_WORD);
    memcpy(LEXICON_INSIDE, "inside", LENGTH_WORD);
    memcpy(LEXICON_INVENTORY, "inventory", LENGTH_WORD);
    memcpy(LEXICON_KEY, "key", LENGTH_WORD);
    memcpy(LEXICON_LIBRARIAN, "librarian", LENGTH_WORD);
    memcpy(LEXICON_LIBRARY, "library", LENGTH_WORD);
    memcpy(LEXICON_LOOK, "look", LENGTH_WORD);
    memcpy(LEXICON_MAIN, "main", LENGTH_WORD);
    memcpy(LEXICON_MANSION, "mansion", LENGTH_WORD);
    memcpy(LEXICON_ME, "me", LENGTH_WORD);
    memcpy(LEXICON_MYSELF, "myself", LENGTH_WORD);
    memcpy(LEXICON_OLD, "old", LENGTH_WORD);
    memcpy(LEXICON_ON, "on", LENGTH_WORD);
    memcpy(LEXICON_OUT, "out", LENGTH_WORD);
    memcpy(LEXICON_OUTSIDE, "outside", LENGTH_WORD);
    memcpy(LEXICON_PLAY, "play", LENGTH_WORD);
    memcpy(LEXICON_PLAYER, "player", LENGTH_WORD);
    memcpy(LEXICON_ROOM, "room", LENGTH_WORD);
    memcpy(LEXICON_SECOND, "second", LENGTH_WORD);
    memcpy(LEXICON_SELF, "self", LENGTH_WORD);
    memcpy(LEXICON_SIGN, "sign", LENGTH_WORD);
    memcpy(LEXICON_SHINY, "shiny", LENGTH_WORD);
    memcpy(LEXICON_TAKE, "take", LENGTH_WORD);
    memcpy(LEXICON_THING, "thing", LENGTH_WORD);
    memcpy(LEXICON_THIRD, "third", LENGTH_WORD);
    memcpy(LEXICON_USE, "use", LENGTH_WORD);
    memcpy(LEXICON_WORLD, "world", LENGTH_WORD);
    return;
}

int bool_word_is_in_lexicon(const char* word)
{
    int i;
    for (i = 0; i < NBR_WORDS; ++i)
    {
        if (!list_lexicon[i][0])
            return 0;

        if (!strcmp(word, list_lexicon[i]))
            return 1;
    }
    return 0;
}

int bool_word_is_preposition(const char* word)
{
    return !strcmp(word, "on");
}

