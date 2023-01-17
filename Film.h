#ifndef FILM
#define FILM

#include "Video.h"

class Film : public Video {
    private :
        int * chapters {};
        int nb_chapters {};

    public :
        Film(){}
        Film(
            int * _chapters,
            int _nb_chapters,
            std::string _name,
            std::string _filepath,
            int _duration
        ) : Video(_name, _filepath, _duration), nb_chapters{_nb_chapters} {
            chapters = new int[_nb_chapters];
            for (int i=0; i< _nb_chapters;i++){
                chapters[i]=_chapters[i];
            } 
        }
        ~Film() override {delete[] chapters;}
        void setChapters(int * _chapters, int _nb_chapters){
            nb_chapters = _nb_chapters;
            delete[] chapters;
            chapters = new int[_nb_chapters];
            for (int i=0; i<_nb_chapters;i++){
                chapters[i]=_chapters[i];
            }
        }
        const int * getChapters() const{
            return chapters;
        }
        int getNbChapters() const {
            return nb_chapters;
        }
        void display(std::ostream & os) const override {
            Video::display(os);
            os << "number of chapters : " << nb_chapters << "\n";
            for (int i=0; i<nb_chapters; i++){
                os << "duration of chapter " << i << " : " << chapters[i] << "\n";
            }
        }

};

#endif