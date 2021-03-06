#ifndef PATIENT
#define PATIENT

#include <string>
#include <ctime>

#include "Utilities/countriescode.h"

class Patient
{
    // According to form 003/о from 14.02.2012 No 110 / redaction 21.01.2016 No 29

    // Page 1
    public: int id;
    public: std::tm hospitalisationDate;
    public: int sex; // 1 - male, 2 - female
    public: std::string lastName;
    public: std::string firstName;
    public: std::string fatherName;
    public: std::tm dateOfBirth;
    public: int age() const noexcept
    {
        std::time_t t = std::time(NULL);
        return std::tm(*std::localtime(&t)).tm_year - dateOfBirth.tm_year;
    }
    public: std::string idDocumentType;
    public: std::string idDocumentNumber;
    public: Country citizenship;
    public: int permanentResidenceKey; // 1 - city, 2 - country
    public: std::string permanentResidenceAddress; // region, area, settlement, street, building, apartment
    public: long permanentResidenceZipCode;
    public: std::string placeOfJob; //or study
    public: std::string sender;
    public: long senderCodeYEDRPOU;
    public: std::string hospitalisationDiagnosis;
    public: std::string hospitalisationDiagnosisCodeMKX10;
    public: std::string hospitalisationDepartment;
    public: std::string writingOutDepartment;
    public: int hospitalisationKey; // 1 - urgent, 2 - planned
    public: std::tm HIV_AIDSobservation;
    public: std::string bloodType;
    public: std::string RhAffiliation;
    public: std::tm VasermanaReaction;
    public: std::string allergicReactions; // name of the drug, the nature of side effects
    public: int hospitalisationInCurrentYear; // 1 - firstly, 2 - repeatedly
    public: int hospitalisationRepeatedlyInMonth; // 1 - yes, 2 - no
    public: std::tm writingOutDate; // or death date
    public: int hospitalisationDays() const noexcept
    {
        std::tm t1 = writingOutDate;
        std::tm t2 = hospitalisationDate;
        return std::difftime(std::mktime(&t1),std::mktime(&t2))/86400;
    }

    // Page 2
    public: Patient(){}
    public: ~Patient(){}
};

#endif // PATIENT

