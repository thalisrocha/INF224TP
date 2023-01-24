#ifndef FILM
#define FILM

#include "Video.h"

class Film : public Video {
    private :
        int * chapters {};
        int nb_chapters {};
    protected :
        Film(){}
        Film(
            std::string _name,
            std::string _filepath,
            int _duration,
            int * _chapters,
            int _nb_chapters
        ) : Video(_name, _filepath, _duration), nb_chapters{_nb_chapters} {
            chapters = new int[_nb_chapters];
            for (int i=0; i< _nb_chapters;i++){
                chapters[i]=_chapters[i];
            } 
        }
        friend class DataBase;
    public :
        Film(const Film & from) : Video(from) {
            nb_chapters = from.nb_chapters;
            if (from.chapters) {
                chapters = new int[nb_chapters];
                for (int i=0; i<nb_chapters; i++){
                    chapters[i]=from.chapters[i];
                }
            }
            else {
                chapters=nullptr;
            }
        }
        Film& operator=(const Film& from){
            Video::operator=(from);
            nb_chapters = from.nb_chapters;
            delete chapters;
            if (from.chapters) {
                chapters = new int[nb_chapters];
                for (int i=0; i<nb_chapters; i++){
                    chapters[i]=from.chapters[i];
                }
            }
            else {
                chapters=nullptr;
            }
            return *this;
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
        int * getChapters() const{
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