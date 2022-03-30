class Card
{
private:
    double single_arr[1];
    double pairs_arr[2];
    double triples_arr[3];
    double straight_arr[5];
    double flush_arr[5];
    double fullHouse_arr[5];
    double tiki_arr[5];
    double straightFlush_arr[5];
public:
    void single();
    void pairs();
    void triples();
    void straight();
    void flush();
    void fullHouse();
    void tiki();
    void straightFlush();
};