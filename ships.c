#include "ships.h"

void standing_ship(int act_y, ship ship, bool field[10][15]){
    int size_of_ship = convert_size(act_y);
    switch (ship.type){
        case FALSE:
            for (int i = 0; i < size_of_ship-1; i++)
                field[ship.y][i+ship.x] = TRUE;
            break;
        case TRUE:
            for (int i = 0; i < size_of_ship-1; i++)
                field[i+ship.y][ship.x] = TRUE;
            break;
    }
}

void deleting_ship(int act_y, ship ship, bool field[10][15]){
    int size_of_ship = convert_size(act_y);
    switch (ship.type){
        case FALSE:
            for (int i = 0; i < size_of_ship-1; i++)
                field[ship.y][i+ship.x] = FALSE;
            break;
        case TRUE:
            for (int i = 0; i < size_of_ship-1; i++)
                field[i+ship.y][ship.x] = FALSE;
            break;
    }
}

void refresh_ship_player_gpaphics(WINDOW *WIN, bool field[10][15]){
    int rect = 254;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++){
            if (field[i][j] == TRUE){
                wattron(WIN, COLOR_PAIR(10));
                mvwprintw(WIN,i*2+3,j*2+3, "%c", rect);
            }
            else {
                wattron(WIN, COLOR_PAIR(3));
                mvwprintw(WIN,i*2+3,j*2+3, " ");
            }
        }
    wrefresh(WIN);
}

bool check_border_left(ship ship){
    if (ship.x == 0)
        return FALSE;
    else 
        return TRUE;
}

bool check_border_right(int act_y, ship ship){
    switch (ship.type){
        case FALSE:
            if (ship.x + convert_size(act_y) == 16)
                return FALSE;
            else 
                return TRUE;
        case TRUE:
            if (ship.x == 14)
                return FALSE;
            else 
                return TRUE;
    }

}

bool check_border_top(ship ship){
    if (ship.y == 0)
        return FALSE;
    else 
        return TRUE;
}

bool check_border_bot(int act_y, ship ship){
    switch (ship.type){
        case TRUE:
            if (ship.y + convert_size(act_y) == 11)
                return FALSE;
            else 
                return TRUE;
        case FALSE:
            if (ship.y == 9)
                return FALSE;
            else 
                return TRUE;
    }
}

bool check_ship_left(int act_y, ship ship, bool field[10][15]){
    switch (ship.type){
        case TRUE: ;
            for (int i = 0; i < convert_size(act_y)-1; i++){
                if (field[ship.y+i][ship.x-1] == TRUE)
                    return FALSE;
            }
            return TRUE;

        case FALSE:
            if (field[ship.y][ship.x-1] == FALSE)
                return TRUE;
            else
                return FALSE;
    }     
}

bool check_ship_right(int act_y, ship ship, bool field[10][15]){
    switch (ship.type){
        case TRUE: ;
            for (int i = 0; i < convert_size(act_y)-1; i++){
                if (field[ship.y+i][ship.x+1] == TRUE)
                    return FALSE;
            }
            return TRUE;

        case FALSE:
            if (field[ship.y][ship.x+convert_size(act_y)-1] == FALSE)
                return TRUE;
            else
                return FALSE;
    }     
}

bool check_ship_top(int act_y, ship ship, bool field[10][15]){
    switch (ship.type){
        case FALSE: ;
            for (int i = 0; i < convert_size(act_y)-1; i++){
                if (field[ship.y-1][ship.x+i] == TRUE)
                    return FALSE;
            }
            return TRUE;

        case TRUE:
            if (field[ship.y-1][ship.x] == FALSE)
                return TRUE;
            else
                return FALSE;
    }     
}

bool check_ship_bot(int act_y, ship ship, bool field[10][15]){
    switch (ship.type){
        case FALSE: ;
            for (int i = 0; i < convert_size(act_y)-1; i++){
                if (field[ship.y+1][ship.x+i] == TRUE)
                    return FALSE;
            }
            return TRUE;

        case TRUE:
            if (field[ship.y+convert_size(act_y)-1][ship.x] == FALSE)
                return TRUE;
            else
                return FALSE;
    }  
}

int convert_index_to_active_y(int index){
    if (index == 0 || index == 1)
        return 5;
    if (index == 2 || index == 3 || index == 4 )
        return 7;
    if (index == 5 || index == 6 || index == 7 || index == 8)
        return 9;
    if (index == 9 || index == 10 || index == 11 || index == 12 || index == 13 || index == 14 )
        return 11;
}

int convert_ship_index(int y, int x){
    switch (y)
    {
    case 5:
        if (x == 13)
            return 0;
        else 
            return 1;
        break;
    case 7:
        if (x == 13)
            return 2;
        if (x == 17)
            return 3;
        if (x == 21)
            return 4;
        break;
    case 9:
        if (x == 13)
            return 5;
        if (x == 16)
            return 6;
        if (x == 19)
            return 7;
        if (x == 22)
            return 8;
    case 11:
        if (x == 13)
            return 9;
        if (x == 15)
            return 10;
        if (x == 17)
            return 11;
        if (x == 19)
            return 12;
        if (x == 21)
            return 13;
        if (x == 23)
            return 14;
    default:
        break;
    }
}

bool check_ship_borders_top_bottom_horizontal(int size_of_ship, ship ship, bool field[10][15]){
    switch (ship.y){
        case 0: { 
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+1][ship.x+i] == TRUE)
                    return FALSE;
            return TRUE;
        }
        case 9: {
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y-1][ship.x+i] == TRUE)
                    return FALSE;
            return TRUE;
        }
        default:{
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y-1][ship.x+i] == TRUE)
                    return FALSE;
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+1][ship.x+i] == TRUE)
                    return FALSE;
            return TRUE;
        }
    }
}

bool check_ship_borders_left_right_horizontal(int size_of_ship, ship ship, bool field[10][15]){
    if (ship.x + size_of_ship == 15){
        if (ship.y == 0)
            if (field[0][ship.x-1] == TRUE || field[1][ship.x-1] == TRUE)
                return FALSE;
        if (ship.y == 9)
            if (field[9][ship.x-1] == TRUE || field[8][ship.x-1] == TRUE)
                return FALSE;
        if (ship.y != 0 && ship.y != 9)
            for(int i = ship.y-1; i <= ship.y+1; i++)
                if (field[i][ship.x-1] == TRUE)
                    return FALSE;
    } else 
    if (ship.x == 0){
        if (ship.y == 0)
            if (field[0][size_of_ship] == TRUE || field[1][size_of_ship] == TRUE)
                return FALSE;
        if (ship.y == 9)
            if (field[9][size_of_ship] == TRUE || field[8][size_of_ship] == TRUE)
                return FALSE;
        if (ship.y != 0 && ship.y != 9)
            for(int i = ship.y-1; i <= ship.y+1; i++)
                if (field[i][ship.x+size_of_ship] == TRUE)
                    return FALSE;
    } else
    for (int i = ship.y-1; i <= ship.y+1; i++)
        if (field[i][ship.x+size_of_ship] == TRUE || field[i][ship.x-1] == TRUE)
            return FALSE;
    return TRUE;
}

bool check_ship_borders_left_right_vertical(int size_of_ship, ship ship, bool field[10][15]){
    switch (ship.x){
        case 0: { 
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+i][ship.x+1] == TRUE)
                    return FALSE;
            return TRUE;
        }
        case 14: {
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+i][ship.x-1] == TRUE)
                    return FALSE;
            return TRUE;
        }
        default:{
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+i][ship.x+1] == TRUE)
                    return FALSE;
            for (int i = 0; i < size_of_ship; i++)
                if (field[ship.y+i][ship.x-1] == TRUE)
                    return FALSE;
            return TRUE;
        }
    }
}
bool check_ship_borders_top_bottom_vertical(int size_of_ship, ship ship, bool field[10][15]){
    if (ship.y + size_of_ship == 10){
        if (ship.x == 0)
            if (field[ship.y-1][ship.x] == TRUE || field[ship.y-1][ship.x+1] == TRUE)
                return FALSE;
        if (ship.x == 14)
            if (field[ship.y-1][ship.x] == TRUE || field[ship.y-1][ship.x-1] == TRUE)
                return FALSE;
        if (ship.x != 0 && ship.x != 14)
            for (int i = ship.x-1; i <= ship.x+1; i++)
                if (field[ship.y-1][i] == TRUE)
                    return FALSE;
    } else 
    if (ship.y == 0){
        if (ship.x == 0)
            if (field[size_of_ship][ship.x] == TRUE || field[size_of_ship][ship.x+1] == TRUE)
                return FALSE;
        if (ship.x == 14)
            if (field[size_of_ship][ship.x] == TRUE || field[size_of_ship][ship.x-1] == TRUE)
                return FALSE;
        if (ship.x != 0 && ship.x != 14)
            for (int i = ship.x-1; i <= ship.x+1; i++)
                if (field[size_of_ship][i] == TRUE)
                    return FALSE;
    } else 
    for (int i = ship.x-1; i <= ship.x+1; i++)
        if (field[ship.y-1][i] == TRUE || field[ship.y+size_of_ship][i] == TRUE)
            return FALSE;
    return TRUE;
}