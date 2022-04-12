#include "../headers/drop.h"
#include "../headers/commands.h"
#include "../headers/items.h"

void execute_drop(void)
{
    int i;
    SameTag* items_with_same_tag = NULL;

    if (PLAYER->current_location->list_of_items_by_id[NBR_ITEMS - 1] != ID_ITEM_NONE)
    {
        printf("\nThis place cannot hold any more item.\n\n");
        return;
    }
    else if (PLAYER->list_of_items_by_id[0] == ID_ITEM_NONE)
    {
        printf("\nYou have no item on you.\n\n");
        return;
    }
    else if (strcmp(command.object, "") != 0)
    {
        items_with_same_tag = retrieve_item_id_by_parser_from_inventory(command.object);

        if (!items_with_same_tag || items_with_same_tag[0].id == ID_ITEM_NONE)
        {
            memcpy(command.object, "", BIG_LENGTH_WORD);
        }
        else if (items_with_same_tag[1].id != ID_ITEM_NONE)
        {
            /* TODO: The second tag is picked, but it may still be identical, so the retrieval function needs to provide the index of the proper tag (index, id, tag) */
            printf("\nThere is more than one item in your inventory for which this tag works.\n\n");
            printf("\n\t[Drop what? There is more than one item in your inventory for which this tag works. Try:]\n");
            for (i = 0; i < NBR_ITEMS; ++i)
            {
                if (items_with_same_tag[i].id == ID_ITEM_NONE)
                    break;
                printf("\t\t['Drop %s'.]\n", list_items[items_with_same_tag[i].id].tags[1]);
            }
            printf("\n");
        }
        else if (PLAYER->current_location->list_of_items_by_id[NBR_ITEMS - 1] != ID_ITEM_NONE)
        {
            printf("\nThe current location is full. No more items can be added.\n\n");
        }
        else
        {
            for (i = 0; i < NBR_ITEMS; ++i)
            {
                if (PLAYER->current_location->list_of_items_by_id[i] == ID_ITEM_NONE)
                {
                    PLAYER->current_location->list_of_items_by_id[i] = items_with_same_tag[0].id;
                    PLAYER->list_of_items_by_id[items_with_same_tag[0].index] = ID_ITEM_NONE;

                    for (i = NBR_ITEMS - 1; i >= 0; --i)
                    {
                        if (PLAYER->list_of_items_by_id[i] != ID_ITEM_NONE)
                        {
                            if (i != items_with_same_tag[0].index)
                            {
                                PLAYER->list_of_items_by_id[items_with_same_tag[0].index] = PLAYER->list_of_items_by_id[i];
                                PLAYER->list_of_items_by_id[i] = ID_ITEM_NONE;
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            printf("\n'%s' dropped.\n\n", list_items[items_with_same_tag[0].id].name);
        }
    }

    if (strcmp(command.object, "") == 0)
    {
        if (PLAYER->list_of_items_by_id[1] == ID_ITEM_NONE)
        {
            printf("\n\t[Drop what? Try 'drop %s'.]\n\n", list_items[PLAYER->list_of_items_by_id[0]].tags[0]);
        }
        else
        {
            printf("\n\t[Drop what? Try:]\n");
            for (i = 0; i < NBR_ITEMS; ++i)
            {
                if (PLAYER->list_of_items_by_id[i] == ID_ITEM_NONE)
                    break;
                printf("\t\t['Drop %s'.]\n", list_items[PLAYER->list_of_items_by_id[i]].tags[0]);
            }
            printf("\n");
        }
    }

    free(items_with_same_tag);
    return;
}

