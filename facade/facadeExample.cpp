#include <iostream>
#include <string>

class Amplifier {
public:
    void on() { std::cout << "Amplifier on\n"; }
    void off() { std::cout << "Amplifier off\n"; }
    void setDVD(const std::string& dvd) { std::cout << "Amplifier setting DVD to " << dvd << "\n"; }
    void setSurroundSound() { std::cout << "Amplifier surround sound on\n"; }
    void setVolume(int level) { std::cout << "Amplifier setting volume to " << level << "\n"; }
};

class Tuner {
    // Implementation of Tuner methods
};

class DVDPlayer {
public:
    void on() { std::cout << "DVD Player on\n"; }
    void off() { std::cout << "DVD Player off\n"; }
    void play(const std::string& movie) { std::cout << "DVD Player playing \"" << movie << "\"\n"; }
    void stop() { std::cout << "DVD Player stopped\n"; }
};

class Projector {
public:
    void on() { std::cout << "Projector on\n"; }
    void off() { std::cout << "Projector off\n"; }
    void wideScreenMode() { std::cout << "Projector in widescreen mode\n"; }
};

class Screen {
public:
    void down() { std::cout << "Screen down\n"; }
    void up() { std::cout << "Screen up\n"; }
};

class TheaterLights {
public:
    void dim(int level) { std::cout << "Theater Lights dimming to " << level << "%\n"; }
    void on() { std::cout << "Theater Lights on\n"; }
};

class PopcornPopper {
public:
    void on() { std::cout << "Popcorn Popper on\n"; }
    void off() { std::cout << "Popcorn Popper off\n"; }
    void pop() { std::cout << "Popcorn Popper popping corn\n"; }
};

class HomeTheaterFacade {
private:
    Amplifier* amp;
    Tuner* tuner;
    DVDPlayer* dvd;
    Projector* projector;
    Screen* screen;
    TheaterLights* lights;
    PopcornPopper* popper;

public:
    HomeTheaterFacade(Amplifier* amp, Tuner* tuner, DVDPlayer* dvd, Projector* projector, Screen* screen, TheaterLights* lights, PopcornPopper* popper)
        : amp(amp), tuner(tuner), dvd(dvd), projector(projector), screen(screen), lights(lights), popper(popper) {}

    void watchMovie(const std::string& movie) {
        std::cout << "Get ready to watch a movie...\n";
        popper->on();
        popper->pop();
        lights->dim(10);
        screen->down();
        projector->on();
        projector->wideScreenMode();
        amp->on();
        amp->setDVD(movie);
        amp->setSurroundSound();
        amp->setVolume(5);
        dvd->on();
        dvd->play(movie);
    }

    void endMovie() {
        std::cout << "Shutting movie theater down...\n";
        popper->off();
        lights->on();
        screen->up();
        projector->off();
        amp->off();
        dvd->stop();
        dvd->off();
    }
};

int main() {
    Amplifier amp;
    Tuner tuner;
    DVDPlayer dvd;
    Projector projector;
    Screen screen;
    TheaterLights lights;
    PopcornPopper popper;

    HomeTheaterFacade homeTheater(&amp, &tuner, &dvd, &projector, &screen, &lights, &popper);

    homeTheater.watchMovie("Raiders of the Lost Ark");
    homeTheater.endMovie();

    return 0;
}