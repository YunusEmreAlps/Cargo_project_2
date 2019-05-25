// final project

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// structure

struct time // duration
{
    int min_t ; // minimum time
    int max_t ; // maximum time
};

struct fee // money
{
    float c_kg ; // cargo kg

    float net_f ; // net fee
    float ext_f ; // extra fee
    float tot_f ; // total fee

    struct time *dur ; // link
};

struct person // customer personal information
{
    int c_id ; // cargo id

    char name[25] ; // person name
    char surname[20] ; // person surname

    struct fee *mon ; // link
};

// structure part is complete

// -------------------- --------------------

// global variable

FILE *data ;

struct person *per ;

int p_count = 0 ; // person counter
int pc ; // p_count - 1
int counter_se = 0 ; // this variable count ( se_num == (per+i)->c_id)
int i, j, k, m, t, n ;      // loop variable

float ex_del = 0.0 ; // delivery type
float ex_mod = 0.0 ; // delivery mode
float packet = 0.0 ; // packet fee
float ex_res = 0.0 ; // extra result

// -------------------- --------------------

// function

int menu_language() ; // tr - en
int tr_status() ;     // worker - customer
int password() ;      // ****
int menu_worker() ;   // add - delete - update - list ...
int menu_customer() ; // fee - time

void add() ; // add customer
void del() ; // delete customer
void update() ; // update customer information
void search() ; // search customer
void list() ; // list customer data

int extra(int ex_num, float net_num) ;  // extra fee ( add )
int max_time(float net_num) ; // maximum delivery time ( add )

void disp_f() ; // display fee  ( customer menu )
void disp_t() ; // display time ( customer menu )
void f_read() ; // file read function

int menu_update() ; // name - surname - kg

void upd_name(int index) ; // update name
void upd_surname(int index) ; // update surname
void upd_kg(int index) ; // update kg
void disp_up(int index) ; // display update
void up_write(int index) ; // file update write function

// -------------------- --------------------

int main()
{
    int work_num = 0 ; // use worker menu part
    int cust_num = 0 ; // use customer menu part

    f_read() ; // file read ( important )

    while(1)
    {
        // menu language

        system("cls") ;
        printf(" \n -------------------- \n ") ; // 20

        int lang_num = 0 ; // language number
        lang_num = menu_language() ;

        printf(" \n -------------------- \n ") ;
        system("cls") ;

        // menu language part is complete

        if(lang_num == 1) // tr
        {
            while(1)
            {
                // status part

                system("cls") ;
                printf(" \n -------------------- \n ") ;

                int sta_num = 0 ; // status number
                sta_num = tr_status() ;

                if(sta_num == 3) // language menu
                {
                    break ;
                }

                printf(" \n -------------------- \n ") ;
                system("cls") ;

                // status part is complete

                if(sta_num == 1) // password
                {
                    system("cls") ;
                    printf(" \n -------------------- \n ") ;

                    int pass_cont = -1 ; // password control
                    pass_cont = password() ;

                    if(pass_cont == 0) // false
                    {
                        printf(" \n - Girisiniz reddedildi ") ;
                        getch() ;
                        sta_num = 2 ;
                    }

                    else if (pass_cont == 1) // true
                    {
                        printf(" \n - Sifreniz dogru \n ") ;
                        printf(" \n - Sisteme giris yapiliyor ... ") ;
                        getch() ;
                        sta_num = 1 ;
                    }

                    printf(" \n -------------------- \n ") ;
                    system("cls") ;

                }

                // password part is complete

                switch(sta_num)
                {
                case 1 : // worker menu

                    // worker menu part

                    system("cls") ;
                    printf(" \n -------------------- \n ") ;

                    work_num = menu_worker() ; // menu function

                    printf(" \n -------------------- \n ") ;
                    system("cls") ;

                    // worker menu part is complete



                    switch(work_num)
                    {
                    case 1 : // add customer

                        add() ;
                        printf(" \n - Isleminiz tamamlanmistir . \n ") ;
                        getch() ;
                        break ;

                    case 2 : // delete customer

                        del() ;
                        printf(" \n - Isleminiz tamamlanmistir . \n ") ;
                        getch() ;
                        break ;

                    case 3 : // update customer information

                        update() ;
                        break ;

                    case 4 : // search

                        search() ;
                        break ;

                    case 5 : // list all customer information

                        list() ;
                        getch() ;
                        break ;

                    case 6 : // return

                        break ;

                    case 7 : // exit

                        printf(" \n - Alpu Kargo \n ") ;
                        printf(" \n - Bizi tercih ettiginiz icin tesekkur ederiz . \n ") ;
                        getch() ;
                        break ;
                    }

                    break ;

                // -------------------- --------------------

                case 2 : // customer menu

                    // customer menu part

                    system("cls") ;
                    printf(" \n -------------------- \n ") ;

                    cust_num = menu_customer() ;

                    printf(" \n -------------------- \n ") ;
                    system("cls") ;

                    // customer menu part is complete

                    switch(cust_num)
                    {
                    case 1 : // fee

                        add() ;
                        disp_f() ;
                        getch() ;

                        break ;

                    case 2 : // time

                        add() ;
                        disp_t() ;
                        getch() ;

                        break ;

                    case 3 : // return

                        break ;

                    case 4 : // exit

                        printf(" \n - Alpu Kargo \n ") ;
                        printf(" \n - Bizi tercih ettiginiz icin tesekkur ederiz . \n ") ;
                        getch() ;
                        break ;

                    }

                    break ;
                }

                if((work_num == 7)||(cust_num == 4)) // exit
                {
                    break ;
                }

            } // while

        } // if

        if((work_num == 7)||(cust_num == 4)) // exit
        {
            break ;
        }

        else if(lang_num == 2)
        {
            printf(" \n - 404 : Page not Found  \n ") ;
            getch() ;
        }


    } // while

    getch() ;
    return 0 ;
}

int menu_language()
{
    float m_lang = 0.0 ; // menu language

    printf(" \n - 1.) Turkce devam etmek icin , lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) For continue in English , please press 2 : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : \n ") ;
    printf(" \n - Please enter process number : ") ;

    while(1) // control
    {
        scanf("%f",&m_lang) ;

        if((m_lang == 1)||(m_lang == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : \n ") ;
        printf(" \n - This number isn't match , please enter process number : ") ;

        while(getchar() != '\n') ; // important
    }

    return m_lang ;
}

int tr_status()
{
    float tr_sta = 0.0 ;

    printf(" \n - 1.) Sirket calisani olarak islem yapmak icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Bireysel veya Kurumsal islem yapmak icin lutfen 2'ye basin : \n ") ;
    printf(" \n - 3.) Geri gitmek icin lutfen 3'e basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1) // control
    {
        scanf("%f",&tr_sta) ;

        if((tr_sta == 1)||(tr_sta == 2)||(tr_sta == 3))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ; // important
    }

    return tr_sta ;
}

int password()
{
    float pass = 0.0 ; // password

    int p_count = 0, control = -1 ;  // password counter and control

    printf(" \n - Lutfen sifrenizi girin : ") ;

    while(1)
    {
        scanf("%f",&pass) ;

        if((pass == 10111901)||(pass == 10111902)||(pass == 10111903)||(pass == 10111904)||(pass == 10111905)||
                (pass == 10111906)||(pass == 10111907)||(pass == 10111908)||(pass == 10111909))
        {
            control = 1 ; // true
            break ;
        }

        p_count++ ;

        if(3-(p_count) != 0)
        {

            printf(" \n -------------------- \n ") ;

            printf(" \n - Kalan kullanim hakki : %d \n ",3-(p_count)) ;
            printf(" \n - Sifre yanlis , lutfen tekrar deneyiniz : ") ;

        }

        while(getchar() != '\n') ;

        if(p_count == 3)
        {
            control = 0 ; // false
            break ;
        }
    }

    return control ;
}

int menu_worker()
{
    float m_work = 0.0 ; // menu worker

    printf(" \n - Menu dili : Turkce \n ") ;

    printf(" \n - 1.) Kullanici ekleme islemi icin lutfen 1'e basin : \n ") ; // add
    printf(" \n - 2.) Kullanici silme islemi icin lutfen 2'ye basin : \n ") ; // delete
    printf(" \n - 3.) Kayit guncelleme islemi icin lutfen 3'e basin : \n ") ; // update
    printf(" \n - 4.) Kayit arama islemi icin lutfen 4'e basin : \n ") ; // extra properties
    printf(" \n - 5.) Kullanici verilerini listelemek icin 5'e basin : \n ") ; // list
    printf(" \n - 6.) Geri gitmek icin lutfen 6'ya basin : \n ") ;
    printf(" \n - 7.) Cikis icin lutfen 7'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&m_work) ;

        if((m_work == 1)||(m_work == 2)||(m_work == 3)||(m_work == 4)||(m_work == 5)||(m_work == 6)||(m_work == 7))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }

    return m_work ;
}

int menu_customer()
{
    float m_cus = 0.0 ; // menu customer

    printf(" \n - Menu dili : Turkce \n ") ;

    printf(" \n - 1.) Gonderi fiyat hesaplama islemi icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Gonderi teslimat suresini hesaplama islemi icin lutfen 2'ye basin : \n ") ;
    printf(" \n - 3.) Geri gitmek icin lutfen 3'e basin : \n ") ;
    printf(" \n - 4.) Cikis icin lutfen 4'e basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&m_cus) ;

        if((m_cus == 1)||(m_cus == 2)||(m_cus == 3)||(m_cus == 4))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }

    return m_cus ;
}

void add() // +
{

    // -------------------- --------------------

    p_count++ ; // person number ( important ) global variable

    // -------------------- --------------------

    pc = p_count - 1 ; // index


    // -------------------- --------------------

    if(p_count == 1) // dynamic memory
    {
        per = malloc((p_count)*sizeof(struct person)) ;
    }

    else if(p_count > 1)
    {
        per = realloc(per,(p_count)*sizeof(struct person)) ;
    }

    // -------------------- --------------------

    for(i = 0 ; i<1 ; i++)
    {
        printf(" \n - Lutfen 4 haneli musteri numaranizi girin : ") ;

        while(1)
        {
            int control = -1 ; // c_id control

            scanf("%d",&((per+pc)->c_id)) ;

            if((((per+pc)->c_id)>999)&&(((per+pc)->c_id)<10000))
            {
                if(p_count == 1)
                {
                    break ;
                }

                else if(p_count > 1)
                {
                    for(m = 0 ; m<p_count-1 ; m++)
                    {
                        if(((per+pc)->c_id) == ((per+m)->c_id))
                        {
                            control = 1 ; // true
                        }

                        else if(((m+1) == (p_count-1))&&(control != 1))
                        {
                            control = 0 ; // false
                        }
                    }
                }

                if(control == 0)
                {
                    break ;
                }
            }

            if(control == 1)
            {
                printf(" \n -------------------- \n ") ;

                printf(" \n - Girmis oldugunuz id baska bir kullaniciya aittir . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            if(control != 1)
            {
                printf(" \n -------------------- \n ") ;

                printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;
            }

            while(getchar() != '\n') ;
        }

        // -------------------- --------------------

        system("cls") ;
        getchar() ;

        printf(" \n - Lutfen adinizi girin : ") ;

        while(1)
        {
            int len = 0 ; // length
            int counter = 0, control = -1 ;  // string control

            gets((per+pc)->name) ;

            len = strlen((per+pc)->name) ;

            if((len > 0)&&(len < 25))
            {
                for(i = 0 ; i<len ; i++)
                {
                    if( ((((per+pc)->name[i]) >= 'a') && (((per+pc)->name[i]) <= 'z'))||((((per+pc)->name[i]) >= 'A') && (((per+pc)->name[i]) <= 'Z')))
                    {
                        counter++ ;
                    }

                    if(((per+pc)->name[i]) == ' ')
                    {
                        counter++ ;
                    }

                    if(((i+1) == len)&&(counter == len))
                    {
                        control = 1 ; // true
                    }
                }

                if(control == 1)
                {
                    break ;
                }

                printf(" \n -------------------- \n ") ;

                printf(" \n - Sayisal deger girdiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            if(len > 25)
            {
                printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }
        }

        // -------------------- --------------------

        system("cls") ;
        printf(" \n - Lutfen soyadinizi girin : ") ;

        while(1)
        {
            int len = 0 ; // length
            int counter = 0, control = -1 ;  // string control

            gets((per+pc)->surname) ;

            len = strlen((per+pc)->surname) ;

            if((len > 0)&&(len < 20))
            {
                for(i = 0 ; i<len ; i++)
                {
                    if( ((((per+pc)->surname[i]) >= 'a') && (((per+pc)->surname[i]) <= 'z'))||((((per+pc)->surname[i]) >= 'A') && (((per+pc)->surname[i]) <= 'Z')))
                    {
                        counter++ ;
                    }

                    if(((per+pc)->surname[i]) == ' ')
                    {
                        counter++ ;
                    }

                    if(((i+1) == len)&&(counter == len))
                    {
                        control = 1 ; // true
                    }
                }


                if(control == 1)
                {
                    break ;
                }

                printf(" \n -------------------- \n ") ;

                printf(" \n - Sayisal deger girdiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            if(len > 20)
            {
                printf(" \n -------------------- \n ") ;

                printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

        }

        // -------------------- --------------------

        (per + pc)->mon = malloc(1 * sizeof(struct fee)) ;

        j=0 ;
        system("cls") ;
        printf(" \n - Lutfen kargo agirliginizi girin : ") ;

        while(1)
        {
            scanf("%f",&(((per+pc)->mon+j)->c_kg)) ;

            if(((((per+pc)->mon+j)->c_kg) < 2000)&&((((per+pc)->mon+j)->c_kg) > 0))
            {
                break ;
            }

            else if((((per+pc)->mon+j)->c_kg) > 2000)
            {
                printf(" \n -------------------- \n ") ;

                printf(" \n - Girmis oldugunuz deger hizmet sinirini asmaktadir . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            else
            {
                printf(" \n -------------------- \n ") ;

                printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;
            }

            while(getchar() != '\n') ;
        }

        float s_sta = 0.0 ; // second status part

        system("cls") ;
        printf(" \n -------------------- \n ") ;

        printf(" \n - 1.) Bireysel musteri olarak islem yapmak icin lutfen 1'e basin : \n ") ;
        printf(" \n - 2.) Kurumsal musteri olarak islem yapmak icin lutfen 2'ye basin : \n ") ;

        printf(" \n -------------------- \n ") ;

        printf(" \n - Lutfen islem numaranizi girin : ") ;

        while(1)
        {
            scanf("%f",&s_sta) ;

            if((s_sta == 1)||(s_sta == 2))
            {
                break ;
            }

            printf(" \n -------------------- \n ") ;

            printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

            while(getchar() != '\n') ;

        }

        int sta = s_sta ; // status

        if(sta == 1)
        {
            (((per+pc)->mon+j)->net_f) = 2 * (((per+pc)->mon+j)->c_kg) ;
        }

        else if(sta == 2)
        {
            (((per+pc)->mon+j)->net_f) = (((per+pc)->mon+j)->c_kg) ;
        }

        (((per+pc)->mon+j)->ext_f) = extra(sta,(((per+pc)->mon+j)->net_f)) ;
        (((per+pc)->mon+j)->tot_f) = (((per+pc)->mon+j)->net_f) + (((per+pc)->mon+j)->ext_f) ;

        (((per + pc)->mon + j)->dur) = malloc(1 * sizeof(struct time)) ;


        k=0 ;
        system("cls") ;

        if((((per+pc)->mon+j)->c_kg) <= 600)
        {
            ((((per+pc)->mon+j)->dur+k)->min_t) = 1 ;
        }

        else if(((((per+pc)->mon+j)->c_kg) > 600)&&((((per+pc)->mon+j)->c_kg) <= 1000))
        {
            ((((per+pc)->mon+j)->dur+k)->min_t) = 2 ;
        }

        else
        {
            ((((per+pc)->mon+j)->dur+k)->min_t) = 3 ;
        }

        ((((per+pc)->mon+j)->dur+k)->max_t) = max_time((((per+pc)->mon+j)->c_kg)) ;
    }


    data = fopen("database.txt","a+") ; // w -> write

    if(data == NULL)
    {
        printf(" \n - Hata , dosya acilamadi . \n ") ;
        getch() ;
        exit(1) ;
    }

    else
    {
        j=0 ;
        k=0 ;

        fprintf(data," %d - %s - %s - %f - %f - %f - %f - %d - %d \n",((per+pc)->c_id),((per+pc)->name),((per+pc)->surname),
                (((per+pc)->mon+j)->c_kg),(((per+pc)->mon+j)->net_f),(((per+pc)->mon+j)->ext_f),(((per+pc)->mon+j)->tot_f),
                ((((per+pc)->mon+j)->dur+k)->min_t),((((per+pc)->mon+j)->dur+k)->max_t)) ;

        // id - name - surname - kg - net_fee - ext_fee - tot_fee - min_time - max_time

        fclose(data) ;
    }
}

int extra(int ex_num, float net_num)
{
    ex_res = 0.0 ;

    system("cls") ;
    printf(" \n -------------------- \n ") ;

    printf(" \n - 1.) Kargo gonderim tipi subede teslim ise lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Kargo gonderim tipi adresten alim ise lutfen 2'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&ex_del) ;

        if((ex_del == 1)||(ex_del == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }

    // -------------------- --------------------

    system("cls") ;
    printf(" \n -------------------- \n ") ;

    printf(" \n - 1.) Kargo gonderim sekli telefon ihbar ise lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Kargo gonderim sekli adrese teslim ise lutfen 2'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&ex_mod) ;

        if((ex_mod == 1)||(ex_mod == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }

    // -------------------- --------------------

    system("cls") ;
    printf(" \n -------------------- \n ") ;

    printf(" \n - 1.) Normal kargo paketi icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Ozel kargo paketi icin lutfen 2'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&packet) ;

        if((packet == 1)||(packet == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }

    int pac = packet ;

    if(pac == 1)
    {
        ex_res = ex_res ;
    }

    else if (pac == 2)
    {
        ex_res = ex_res + (net_num * (0.1)) ; // packet fee
    }


    // -------------------- --------------------

    if(ex_num == 1) // individual customer
    {
        if((ex_del == 1)&&(ex_mod == 1))
        {
            ex_res += 0 ; // extra
        }

        else if ((ex_del == 1)&&(ex_mod == 2))
        {
            ex_res += 10 ; // extra
        }

        else if ((ex_del == 2)&&(ex_mod == 1))
        {
            ex_res += 10 ; // extra
        }

        else
        {
            ex_res += 20 ; // extra
        }
    }

    else if (ex_num == 2) // business
    {
        if((ex_del == 1)&&(ex_mod == 1))
        {
            ex_res += 0 ; // extra
        }

        else if ((ex_del == 1)&&(ex_mod == 2)) // discount %10
        {
            ex_res += 9 ; // extra
        }

        else if ((ex_del == 2)&&(ex_mod == 1)) // discount %20
        {
            ex_res += 8 ; // extra
        }

        else
        {
            ex_res += 17 ; // extra
        }
    }

    return ex_res ;
}

int max_time(float net_num)
{
    int tm_max = 0 ; // maximum time

    if(net_num <= 600) // kg
    {
        if((ex_del == 1)&&(ex_mod == 1))
        {
            tm_max = 4 ; // maximum delivery time
        }

        else if(((ex_del == 1)&&(ex_mod == 2))||((ex_del == 2)&&(ex_mod == 1)))
        {
            tm_max = 3 ; // maximum delivery time
        }

        else
        {
            tm_max = 2 ; // maximum delivery time
        }
    }

    else if((net_num > 600)&&(net_num <= 1000)) // kg
    {
        if((ex_del == 1)&&(ex_mod == 1))
        {
            tm_max = 5 ; // maximum delivery time
        }

        else if(((ex_del == 1)&&(ex_mod == 2))||((ex_del == 2)&&(ex_mod == 1)))
        {
            tm_max = 4 ; // maximum delivery time
        }

        else
        {
            tm_max = 3 ;
        }
    }

    else
    {
        if((ex_del == 1)&&(ex_mod == 1))
        {
            tm_max = 6 ; // maximum delivery time
        }

        else if(((ex_del == 1)&&(ex_mod == 2))||((ex_del == 2)&&(ex_mod == 1)))
        {
            tm_max = 5 ; // maximum delivery time
        }

        else
        {

            tm_max = 4 ; // maximum delivery time
        }
    }

    return tm_max ;
}

void disp_f()
{
    pc = p_count - 1 ;
    j=0 ;

    printf(" \n - Net ucret : %.2f \n ",(((per+pc)->mon+j)->net_f)) ;
    printf(" \n - Extra ucret : %.2f \n ",(((per+pc)->mon+j)->ext_f)) ;
    printf(" \n - Total ucret : %.2f \n ",(((per+pc)->mon+j)->tot_f)) ;
}

void disp_t()
{
    pc = p_count - 1 ;
    k=0 ;

    printf(" \n - Minimum time : %d \n ",((((per+pc)->mon+j)->dur+k)->min_t)) ;
    printf(" \n - Maximum time : %d \n ",((((per+pc)->mon+j)->dur+k)->max_t)) ;
}

void f_read()
{
    data = fopen("database.txt","r+") ; // r+ -> read and write

    if(data == NULL)
    {
        printf(" \n - Hata , dosya acilamadi . \n ") ;
        getch() ;
        exit(1) ;
    }

    int f_size = 0 ; // total customer number

    if(p_count == 0)
    {
        f_size = filelength(fileno(data))/ sizeof(struct person) ;
        p_count += f_size ;

        printf(" \n - %d \n ",f_size) ;
        getch() ;

        if(f_size == 0 )
        {
            printf(" \n - Dosyada eleman yok . \n ") ;
            getch() ;
            return ;
        }

        per = malloc((p_count)*sizeof(struct person)) ;

        for(i = 0 ; i<p_count ; i++ )
        {
            j=0, k=0;

            fscanf(data," %d - %s - %s -",&((per+i)->c_id),((per+i)->name),((per+i)->surname)) ;

            (per+i)->mon = malloc((1)*sizeof(struct fee)) ;

            fscanf(data," %f - %f - %f - %f ",&(((per+i)->mon+j)->c_kg),&(((per+i)->mon+j)->net_f),&(((per+i)->mon+j)->ext_f),&(((per+i)->mon+j)->tot_f)) ;

            (((per+i)->mon+j)->dur) = malloc((1)*sizeof(struct time)) ;

            fscanf(data,"- %d - %d ",&((((per+i)->mon+j)->dur+k)->min_t),&((((per+i)->mon+j)->dur+k)->max_t)) ;

        }
    }

    fclose(data) ;
}

void list()
{
    int control = -1 ;

    printf(" \n - musteri id - ad - soyad - kg - net ucret - extra ucret - total ucret - minimum ulasma gunu - maximum ulasma gunu \n ") ;

    for(i = 0 ; i<p_count ; i++)
    {
        j=0, k=0 ;

        if((((per+i)->c_id)>999)&&(((per+i)->c_id)<10000))
        {
            printf(" \n - %d - %s - %s -",((per+i)->c_id),((per+i)->name),((per+i)->surname)) ;
            printf(" %f - %f - %f - %f -",(((per+i)->mon+j)->c_kg),(((per+i)->mon+j)->net_f),(((per+i)->mon+j)->ext_f),(((per+i)->mon+j)->tot_f)) ;
            printf(" %d - %d ",((((per+i)->mon+j)->dur+k)->min_t),((((per+i)->mon+j)->dur+k)->max_t)) ;
        }

        else
        {
            control = 1 ; // true
        }
    }

    if(control == 1)
    {
        p_count-- ;
    }

}

void search()
{

    float se_num = 0 ;

    // -------------------- --------------------

    system("cls") ;
    printf(" \n -------------------- \n ") ;

    printf(" \n - 1.) Musteri numarasi kullanarak arama yapmak icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Ad ve Soyad kullanarak arama yapmak icin lutfen 2'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1) // control
    {
        scanf("%f",&se_num) ;

        if((se_num == 1)||(se_num == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ; // important
    }

    // -------------------- --------------------

    if(se_num == 1) // search id
    {
        int se_id = 0 ; // search id

        system("cls") ;
        printf(" \n - Lutfen aranacak musteri numarasini girin : ") ;

        while(1)
        {
            scanf("%d",&se_id) ;

            if((se_id > 999)&&(se_id <10000))
            {
                break ;
            }

            printf(" \n -------------------- \n ") ;

            printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;


            while(getchar() != '\n') ;
        }

        for(i = 0 ; i<p_count ; i++) // search loop
        {
            if(se_id == ((per+i)->c_id)) // id control
            {
                for(m = 0 ; m<1 ; m++)
                {
                    printf(" \n %d \t %s \t %s \t",((per+i)->c_id),((per+i)->name),((per+i)->surname)) ;

                    for(j = 0 ; j<1 ; j++)
                    {
                        printf(" %f \t %f \t %f \t %f \t",(((per+i)->mon+j)->c_kg),(((per+i)->mon+j)->net_f),(((per+i)->mon+j)->ext_f),(((per+i)->mon+j)->tot_f)) ;

                        for(k = 0 ; k<1 ; k++)
                        {
                            printf("%d \t %d \n",((((per+i)->mon+j)->dur+k)->min_t),((((per+i)->mon+j)->dur+k)->max_t)) ;
                        }
                    }

                }

                counter_se++ ;
            }

            else if ((counter_se == 0)&&((i+1) == p_count))
            {
                printf(" \n - Aradiginiz musteri numarasina sahip bir kisi bulunamadi . \n ") ;
                getch() ;
            }
        }

        getch() ;

    }

    // -------------------- --------------------

    else if (se_num == 2) // search name and surname
    {
        char se_name[25] ; // search name
        char se_surname[20] ; // search surname

        system("cls") ;
        printf(" \n - Lutfen aranacak musteri adini girin : ") ;

        while(1)
        {
            int len = 0 ; // length
            int counter = 0, control = -1 ;  // string control

            gets(se_name) ;

            len = strlen(se_name) ;

            if((len < 25)&&(len>0))
            {
                for(i = 0 ; i<len ; i++)
                {
                    if( (((se_name[i]) >= 'a') && ((se_name[i]) <= 'z'))||(((se_name[i]) >= 'A') && ((se_name[i]) <= 'Z')))
                    {
                        counter++ ;
                    }

                    if((se_name[i]) == ' ')
                    {
                        counter++ ;
                    }

                    if(((i+1) == len)&&(counter == len))
                    {
                        control = 1 ; // true
                    }
                }

                if(control == 1)
                {
                    break ;
                }

                printf(" \n -------------------- \n ") ;

                printf(" \n - Sayisal deger girdiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            if(len > 25)
            {
                printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }
        }

        // -------------------- --------------------

        system("cls") ;
        printf(" \n - Lutfen aranacak musteri soyadini girin : ") ;

        while(1)
        {
            int len = 0 ; // length
            int counter = 0, control = -1 ;  // string control

            gets(se_surname) ;

            len = strlen(se_surname) ;

            if((len > 0)&&(len < 20))
            {
                for(i = 0 ; i<len ; i++)
                {
                    if( (((se_surname[i]) >= 'a') && ((se_surname[i]) <= 'z'))||(((se_surname[i]) >= 'A') && ((se_surname[i]) <= 'Z')))
                    {
                        counter++ ;
                    }

                    if((se_surname[i]) == ' ')
                    {
                        counter++ ;
                    }

                    if(((i+1) == len)&&(counter == len))
                    {
                        control = 1 ; // true
                    }
                }

                if(control == 1)
                {
                    break ;
                }

                printf(" \n -------------------- \n ") ;

                printf(" \n - Sayisal deger girdiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }

            if(len > 20)
            {
                printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
                printf(" \n - Lutfen tekrar deneyin : ") ;
            }
        }

        // -------------------- --------------------

        int name_size = 0, surname_size = 0 ; // search information size
        int flag = -1 ; // control

        for( i=0 ; i<p_count ; i++)
        {
            for( t=0 ; t<se_name[t] ; t++) // name control
            {
                if(se_name[t] == (per+i)->name[t])
                {
                    name_size++ ;
                }

                if(name_size == strlen((per+i)->name))
                {
                    flag = 1 ; // true

                }
            }

            name_size = 0 ;

            if(flag == 1) // true
            {
                for(n=0 ; n<se_surname[n]; n++) // surname control
                {
                    if(se_surname[n] == (per+i)->surname[n])
                    {
                        surname_size++ ;
                    }

                    if(surname_size == strlen((per+i)->surname))
                    {
                        for(m = 0 ; m<1 ; m++)
                        {
                            printf(" \n %d \t %s \t %s \t",((per+i)->c_id),((per+i)->name),((per+i)->surname)) ;

                            for(j = 0 ; j<1 ; j++)
                            {
                                printf(" %f \t %f \t %f \t %f \t",(((per+i)->mon+j)->c_kg),(((per+i)->mon+j)->net_f),(((per+i)->mon+j)->ext_f),(((per+i)->mon+j)->tot_f)) ;

                                for(k = 0 ; k<1 ; k++)
                                {
                                    printf("%d \t %d \n",((((per+i)->mon+j)->dur+k)->min_t),((((per+i)->mon+j)->dur+k)->max_t)) ;
                                }
                            }

                        }

                        counter_se++ ;
                    }
                }

            }

            surname_size = 0 ;
            flag = 0 ;

            if ((counter_se == 0)&&((i+1) == p_count))
            {
                printf(" \n - Aradiginiz musteri numarasina sahip bir kisi bulunamadi . \n ") ;
                getch() ;
            }

        }
        getch() ;
    }
}

void update()
{

    int se_id = 0 ; // search id

    system("cls") ;
    printf(" \n - Lutfen guncellemek istediginiz musteri numarasini girin : ") ;

    while(1)
    {
        scanf("%d",&se_id) ;

        if((se_id > 999)&&(se_id <10000))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;


        while(getchar() != '\n') ;
    }

    // -------------------- --------------------

    int index = 0 ;

    for(i = 0 ; i<p_count ; i++) // search loop
    {
        if(se_id == ((per+i)->c_id)) // id control
        {
            index = i, j = 0, k = 0 ;

            printf(" \n %d \t %s \t %s \t",((per+i)->c_id),((per+i)->name),((per+i)->surname)) ;
            printf(" %f \t %f \t %f \t %f \t",(((per+i)->mon+j)->c_kg),(((per+i)->mon+j)->net_f),(((per+i)->mon+j)->ext_f),(((per+i)->mon+j)->tot_f)) ;
            printf("%d \t %d \n",((((per+i)->mon+j)->dur+k)->min_t),((((per+i)->mon+j)->dur+k)->max_t)) ;

            counter_se++ ;


            // -------------------- --------------------

            getch() ;

            while(1)
            {
                printf(" \n -------------------- \n ") ;

                int upd_cont = 0 ; // update control

                upd_cont = menu_update(index) ;

                printf(" \n -------------------- \n ") ;

                switch(upd_cont)
                {
                case 1 : // update name

                    upd_name(index) ;
                    break ;

                case 2 : // update surname

                    upd_surname(index) ;
                    break ;

                case 3 :

                    upd_kg(index) ;
                    break ;

                case 4 :

                    disp_up(index) ;
                    up_write(index) ;
                    break ;
                }

                if(upd_cont == 4)
                {
                    break ;
                }

            }


            // write file

            // -------------------- --------------------

        }

        else if ((counter_se == 0)&&((i+1) == p_count))
        {
            printf(" \n - Aradiginiz musteri numarasina sahip bir kisi bulunamadi . \n ") ;
            getch() ;
        }
    }

    getch() ;
}

int menu_update()
{
    float m_upd = 0.0 ; // update menu

    system("cls") ;
    printf(" \n -------------------- \n ") ; // 20

    printf(" \n - 1.) Ad bilgisini degistirmek icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Soyad bilgisini degistirmek icin lutfen 2'ye basin : \n ") ;
    printf(" \n - 3.) Kargo agirlik bilgisini degistirmek icin lutfen 3'e basin : \n ") ;
    printf(" \n - 4.) Islemi sonlandirmak icin lutfen 4'e basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    // -------------------- --------------------

    while(1)
    {
        scanf("%f",&m_upd) ;

        if((m_upd == 1)||(m_upd == 2)||(m_upd == 3)||(m_upd == 4))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;
    }
    return m_upd ;
}

void upd_name(int index) // update name
{
    getchar() ;

    system("cls") ;
    printf(" \n -------------------- \n ") ; // 20

    printf(" \n - Lutfen adinizi girin : ") ;

    while(1)
    {
        int len = 0 ; // length
        int counter = 0, control = -1 ;  // string control

        gets((per+index)->name) ;

        printf("%d",i) ;

        len = strlen((per+i)->name) ;

        if((len > 0)&&(len < 25))
        {
            for(k = 0 ; k<len ; k++)
            {
                if( ((((per+index)->name[k]) >= 'a') && (((per+index)->name[k]) <= 'z'))||((((per+index)->name[k]) >= 'A') && (((per+index)->name[k]) <= 'Z')))
                {
                    counter++ ;
                }

                if(((per+index)->name[k]) == ' ')
                {
                    counter++ ;
                }

                if(((k+1) == len)&&(counter == len))
                {
                    control = 1 ; // true
                }
            }

            if(control == 1)
            {
                break ;
            }

            printf(" \n -------------------- \n ") ;

            printf(" \n - Sayisal deger girdiniz . \n ") ;
            printf(" \n - Lutfen tekrar deneyin : ") ;
        }

        if(len > 25)
        {
            printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
            printf(" \n - Lutfen tekrar deneyin : ") ;
        }
    }

}

void upd_surname(int index) // update surname
{
    getchar() ;

    system("cls") ;
    printf(" \n -------------------- \n ") ; // 20

    printf(" \n - Lutfen soyadinizi girin : ") ;

    while(1)
    {
        int len = 0 ; // length
        int counter = 0, control = -1 ;  // string control

        gets((per+index)->surname) ;

        len = strlen((per+index)->surname) ;

        if((len > 0)&&(len < 20))
        {
            for(k = 0 ; k<len ; k++)
            {
                if( ((((per+index)->surname[k]) >= 'a') && (((per+index)->surname[k]) <= 'z'))||((((per+index)->surname[k]) >= 'A') && (((per+index)->surname[k]) <= 'Z')))
                {
                    counter++ ;
                }

                if(((per+index)->surname[k]) == ' ')
                {
                    counter++ ;
                }

                if(((k+1) == len)&&(counter == len))
                {
                    control = 1 ; // true
                }
            }


            if(control == 1)
            {
                break ;
            }

            printf(" \n -------------------- \n ") ;

            printf(" \n - Sayisal deger girdiniz . \n ") ;
            printf(" \n - Lutfen tekrar deneyin : ") ;
        }

        if(len > 20)
        {
            printf(" \n -------------------- \n ") ;

            printf(" \n - Maksimum karakter limitini astiniz . \n ") ;
            printf(" \n - Lutfen tekrar deneyin : ") ;
        }

    }
}

void upd_kg(int index) // update kg
{
    system("cls") ;
    printf(" \n - Lutfen kargo agirliginizi girinup_write(index) ; : ") ;

    j = 0, k = 0 ;

    while(1)
    {
        scanf("%f",&(((per+index)->mon+j)->c_kg)) ;

        if(((((per+index)->mon+j)->c_kg) < 2000)&&((((per+index)->mon+j)->c_kg) > 0))
        {
            break ;
        }

        else if((((per+index)->mon+j)->c_kg) > 2000)
        {
            printf(" \n -------------------- \n ") ;

            printf(" \n - Girmis oldugunuz deger hizmet sinirini asmaktadir . \n ") ;
            printf(" \n - Lutfen tekrar deneyin : ") ;
        }

        else
        {
            printf(" \n -------------------- \n ") ;

            printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;
        }

        while(getchar() != '\n') ;
    }

    // -------------------- --------------------

    float s_sta = 0.0 ; // second status part

    system("cls") ;
    printf(" \n -------------------- \n ") ;

    printf(" \n - 1.) Bireysel musteri olarak islem yapmak icin lutfen 1'e basin : \n ") ;
    printf(" \n - 2.) Kurumsal musteri olarak islem yapmak icin lutfen 2'ye basin : \n ") ;

    printf(" \n -------------------- \n ") ;

    printf(" \n - Lutfen islem numaranizi girin : ") ;

    while(1)
    {
        scanf("%f",&s_sta) ;

        if((s_sta == 1)||(s_sta == 2))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;

        while(getchar() != '\n') ;

    }

    // -------------------- --------------------

    if(s_sta == 1)
    {
        (((per+index)->mon+j)->net_f) = 2 * (((per+index)->mon+j)->c_kg) ;
    }

    else if(s_sta == 2)
    {
        (((per+index)->mon+j)->net_f) = 1 * (((per+index)->mon+j)->c_kg) ;
    }

    (((per+index)->mon+j)->ext_f) = extra(s_sta,(((per+index)->mon+j)->net_f)) ;
    (((per+index)->mon+j)->tot_f) = (((per+index)->mon+j)->net_f) + (((per+index)->mon+j)->ext_f) ;

    system("cls") ;

    if((((per+index)->mon+j)->c_kg) <= 600)
    {
        ((((per+index)->mon+j)->dur+k)->min_t) = 1 ;
    }

    else if(((((per+index)->mon+j)->c_kg) > 600)&&((((per+index)->mon+j)->c_kg) <= 1000))
    {
        ((((per+index)->mon+j)->dur+k)->min_t) = 2 ;
    }

    else
    {
        ((((per+index)->mon+j)->dur+k)->min_t) = 3 ;
    }

    ((((per+index)->mon+j)->dur+k)->max_t) = max_time((((per+index)->mon+j)->c_kg)) ;

}

void disp_up(int index) // display update
{
    j = 0, k = 0 ;

    printf(" \n - %d \t %s \t %s \t",((per+index)->c_id),((per+index)->name),((per+index)->surname)) ;
    printf(" %f \t %f \t %f \t %f \t",(((per+index)->mon+j)->c_kg),(((per+index)->mon+j)->net_f),(((per+index)->mon+j)->ext_f),(((per+index)->mon+j)->tot_f)) ;
    printf("%d \t %d \n",((((per+index)->mon+j)->dur+k)->min_t),((((per+index)->mon+j)->dur+k)->max_t)) ;

    printf(" \n - Isleminiz tamamlanmistir . \n ") ;
    getch() ;
}

void up_write(int index) // file write update
{
    data = fopen("database.txt","w+") ; // write mode

    if(data == NULL)
    {
        printf(" \n - Hata , dosya acilamadi . \n ") ;
        getch() ;
        exit(1) ;
    }

    else
    {
        for(i = 0 ; i<p_count ; i++)
        {
            j=0 ;
            k=0 ;

            if((((per+i)->c_id)>999)&&(((per+i)->c_id)<10000))
            {
                fprintf(data," %d - %s - %s - %f - %f - %f - %f - %d - %d \n",((per+i)->c_id),((per+i)->name),((per+i)->surname),
                        (((per+i)->mon+j)->c_kg),(((per+i)->mon+j)->net_f),(((per+i)->mon+j)->ext_f),(((per+i)->mon+j)->tot_f),
                        ((((per+i)->mon+j)->dur+k)->min_t),((((per+i)->mon+j)->dur+k)->max_t)) ;
            }

        }
    }

    fclose(data) ;
}

void del()
{

    int se_id = 0 ; // search id
    int ind = -1 ; // index 2

    system("cls") ;
    printf(" \n - Lutfen aranacak musteri numarasini girin : ") ;

    while(1)
    {
        scanf("%d",&se_id) ;

        if((se_id > 999)&&(se_id <10000))
        {
            break ;
        }

        printf(" \n -------------------- \n ") ;

        printf(" \n - Yanlis tuslama , lutfen tekrar deneyin : ") ;


        while(getchar() != '\n') ;
    }

    for(i = 0 ; i<p_count ; i++) // search loop
    {
        if(se_id == ((per+i)->c_id)) // id control
        {
            char del_ch ; // Yes or No

            system("cls") ;
            printf(" \n - Silmek istediginizden emin misiniz :  \n ") ;
            printf(" \n - Evet  ( E ) \n ") ;
            printf(" \n - Hayir ( H ) \n ") ;

            printf(" \n -------------------- \n ") ;

            printf(" \n - Lutfen islem numaranizi girin : ") ;

            while(1)
            {
                scanf("%c",&del_ch) ;

                if((del_ch == 'E')||(del_ch == 'H')||(del_ch == 'e')||(del_ch == 'h'))
                {
                    break ;
                }

                else if ((del_ch != 'E')||(del_ch != 'H')||(del_ch != 'e')||(del_ch != 'h'))
                {
                    printf(" \n -------------------- \n ") ;

                    printf(" \n - Yanlis tuslama , lutfen islem numaranizi girin : ") ;
                }

            }


            if((del_ch == 'E')||(del_ch == 'e'))
            {
                (per+i)->c_id = -1 ;

                ind = i ;

            }

            counter_se++ ;
        }

        else if ((counter_se == 0)&&((i+1) == p_count))
        {
            printf(" \n - Aradiginiz musteri numarasina sahip bir kisi bulunamadi . \n ") ;
            getch() ;
        }
    }


    up_write(ind) ;

    getch() ;

}


