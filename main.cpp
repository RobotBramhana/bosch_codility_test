/**
 * @file main.cpp
 * @author Sudhanva S (pioneer.sudhu@gmail.com)
 * @brief Program coded for codility test at Bosch. 
 * @version 0.1
 * @date 2020-11-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <string>
#include <memory>

using std::cerr; // error reporting; unbuffered
using std::cin;
using std::clog; // logging; buffered
using std::cout;
using std::endl;
using std::flush;
using std::make_shared;
using std::shared_ptr;
using std::string;

/** @brief Namespace name as per specification */
namespace Bosch
{
    /**
     * @brief Base class to be inherited
     * 
     */
    class Car
    {
    protected:
        int m_Milege;
        string m_FuelType;
        /**
         * @brief structure definition and declaration as per specs
         * 
         */
        struct Other_Features
        {
            string m_Transmission;
            int m_SittingCapacity;

            Other_Features(string transmission, int sitting_capacity) : m_Transmission(transmission), m_SittingCapacity(sitting_capacity){};
        } m_OtherFeatures;

    public:
        /**
         * @brief Construct a new Car object
         * 
         * @param mileage 
         * @param fueltype 
         * @param transmission 
         * @param sitting_capacity 
         */
        Car(int mileage, string fueltype, string transmission, int sitting_capacity) : m_Milege(mileage), m_FuelType(fueltype), m_OtherFeatures(transmission, sitting_capacity)
        {
        }
        /**
         * @brief Destroy the Car object
         * 
         */
        ~Car() {}

    protected:
        /**
         * @brief Get the Other Features object
         * 
         * @return shared_ptr<Other_Features> shared pointer of the OtherFeatures object.
         */
        shared_ptr<Other_Features> getOtherFeatures() const
        {
            shared_ptr<Other_Features> of_ptr = make_shared<Other_Features>(m_OtherFeatures);
            return of_ptr;
        }
        /**
         * @brief Get the Milege object
         * 
         * @return int 
         */
        int getMilege() const { return m_Milege; }
        /**
         * @brief Get the Fuel Type object
         * 
         * @return string 
         */
        string getFuelType() const { return m_FuelType; }

        virtual void start() = 0;
        virtual void stop() = 0;
    };
    /**
     * @brief Inherited Car class
     * 
     */
    class Honda : public Car
    {
    public:
        /**
         * @brief Construct a new Honda object with default values
         * 
         */
        Honda() : Car(10, string("Petrol"), string("Auto"), 5)
        {
        }
        /**
         * @brief Start 
         * 
         */
        void start()
        {
            clog << "starting Honda" << endl
                 << flush;
            cout << "Milege = " << this->getMilege() << endl
                 << flush;
            cout << "Fuel type = " << this->getFuelType() << endl
                 << flush;
        }
        /**
         * @brief Stop
         * 
         */
        void stop()
        {
            clog << "Stopping Honda" << endl
                 << flush;
        }
        /**
         * @brief Destroy the Honda object
         * 
         */
        ~Honda()
        {
        }
    };
    /**
     * @brief Inherited Car class
     * 
     */
    class Volkswagen : public Car
    {
    public:
        /**
         * @brief Construct a new Volkswagen object
         * 
         */
        Volkswagen() : Car(7, string("Diesel"), string("Manual"), 5)
        {
        }
        /**
         * @brief Start
         * 
         */
        void start()
        {
            clog << "starting Volkswagen" << endl
                 << flush;
            cout << "Milege = " << this->getMilege() << endl
                 << flush;
            cout << "Fuel type = " << this->getFuelType() << endl
                 << flush;
        }
        /**
         * @brief Stop
         * 
         */
        void stop()
        {
            clog << "Stopping Volkswagen" << endl
                 << flush;
        }
        /**
         * @brief Destroy the Volkswagen object
         * 
         */
        ~Volkswagen()
        {
        }
    };
    /**
     * @brief Template function to start car of any type
     * 
     * @tparam T Object of type T
     * @param t reference to object of type T
     */
    template <typename T>
    void StartEngine(T &t) { t.start(); }
    /**
     * @brief Template function to stop car of any type
     * 
     * @tparam T Object of type T
     * @param t reference to object of type T
     */
    template <typename T>
    void StopEngine(T &t) { t.stop(); }

} // namespace Bosch
/**
 * @brief Main function
 * 
 * @return int 
 */
int main()
{
    string input_string;
    cout << "Please enter the make of the vehicle" << endl
         << flush;
    cin >> input_string;

    if (input_string.compare("Honda"))
    {
        Bosch::Honda h;
        Bosch::StartEngine(h);
        Bosch::StopEngine(h);
    }
    else if (input_string.compare("Volkswagen"))
    {
        Bosch::Volkswagen v;
        Bosch::StartEngine(v);
        Bosch::StopEngine(v);
    }
    else
    {
        cout << "Unknown selection" << endl;
    }

    return 0;
}
