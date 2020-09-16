/* 
 * File:   main.c
 * Author: langer
 *
 * Created on 13 October 2017, 16:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUDIBLE_DISTANCE 250
#define MAX_MESSAGE_LEN 100
#define MAX_LANG_LEN 2

#define ENTER_MESSAGE_EN "Please enter Bob's speed, Tom's speed and Tom's delay behind Bob:"
#define INCORRECT_INPUT_EN "Input was not correct, please start the program again and try to enter correct input!"
#define IN_AUDIBLE_DISTANCE_EN "Bob can still hear Tom, Tom does not need to move at all."
#define COMMUNICATION_IMPOSIBLE_EN "Bob is too fast, he will never hear Tom, no matter the time."
#define TIME_LEFT_EN "seconds it will take Tom to be in audible distance."

#define ENTER_MESSAGE_CZ "Zadejte prosim Pepovu rychlost, Vaskovu rychlost a zpozdeni se kterym Vasek vyrazil"
#define INCORRECT_INPUT_CZ "Probehlo spatne zadani, prosim spustte program znovu a pokuste se zadat platne udaje."
#define IN_AUDIBLE_DISTANCE_CZ "Pepa je v doslechu, Vasek nikam nemusi."
#define COMMUNICATION_IMPOSIBLE_CZ "Pepa jede moc rychle, Vasek ho nikdy nedozene, i kdyby jel treba celou vecnost."
#define TIME_LEFT_CZ "sekund bude trvat, nez bude Vasek v doslechu."

void set_messages(char *m_ent, char *m_inc, char *m_ina, char *m_imp, char *m_tim,
    const char *M_ENT, const char *M_INC, const char *M_INA, const char *M_IMP, const char *M_TIM)
{
    const int message_len = MAX_MESSAGE_LEN + 1;
    strncpy(m_ent, M_ENT, message_len);
    strncpy(m_inc, M_INC, message_len);
    strncpy(m_ina, M_INA, message_len);
    strncpy(m_imp, M_IMP, message_len);
    strncpy(m_tim, M_TIM, message_len);
}

void set_lang(const char *lang, char *m_ent, char *m_inc, char *m_ina, char *m_tim, char *m_imp)
{
    const int lang_len = MAX_LANG_LEN + 1;
    if (strncmp(lang, "CZ", lang_len) == 0) {
        set_messages(m_ent, m_inc, m_ina, m_tim, m_imp, ENTER_MESSAGE_CZ, INCORRECT_INPUT_CZ, IN_AUDIBLE_DISTANCE_CZ,
            COMMUNICATION_IMPOSIBLE_CZ, TIME_LEFT_CZ);
    } else {
        set_messages(m_ent, m_inc, m_ina, m_tim, m_imp, ENTER_MESSAGE_EN, INCORRECT_INPUT_EN, IN_AUDIBLE_DISTANCE_EN,
            COMMUNICATION_IMPOSIBLE_EN, TIME_LEFT_EN);
    }
}

int main(void)
{
    int s_bob, s_tom, delay, time;
    const int m_len = MAX_MESSAGE_LEN;
    char m_enter[m_len], m_incorrect[m_len], m_in_audible[m_len], m_imposible[m_len], m_time_left[m_len];
    
    set_lang("CZ", m_enter, m_incorrect, m_in_audible, m_imposible, m_time_left);
    
    printf("%s ", m_enter);
    if (scanf("%d %d %d", &s_bob, &s_tom, &delay) !=3 || s_bob <= 0 || s_tom <= 0 || delay < 0) {
        printf("%s\n", m_incorrect);
        return 0;
    }
    if (s_bob * delay < MAX_AUDIBLE_DISTANCE) {
        printf("%s\n", m_in_audible);
        return 0;
    }
    if (s_bob >= s_tom) {
        printf("%s\n", m_imposible);
        return 0;
    }
    time = ((s_bob * delay - 250) / (s_tom - s_bob));
    printf("%d %s\n", time, m_time_left);
    return 0;
}