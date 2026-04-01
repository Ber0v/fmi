#pragma once
class Phone
{
public:
	//baza
	Phone();
	Phone(const char* model, unsigned batteryLevel, unsigned OSversion);
	Phone(const Phone& other);
	~Phone();
	Phone& operator=(const Phone& other);

	//methods
	void printPhone() const;
	void watchReels(int min);//-1%
	void playClash(int min); //-3%
	void takePhoto();//-1%
	void update(); // -10 > OS+1 : no
	void charge(int min); // +1%

	//getter
	const char* getModel() const;
	unsigned getBatteryLevel() const;
	unsigned getOSversion() const;
	unsigned getSoundLevel() const;

	//setters
	void setSoundLevel(unsigned level);

private:
	void setModel(const char* model);

private:
	char* model;
	unsigned batteryLevel;
	unsigned OSversion;
	unsigned soundLevel;
};