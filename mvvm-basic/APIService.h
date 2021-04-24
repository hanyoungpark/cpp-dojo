//
// Created by HANYOUNG PARK on 4/13/21.
//

#ifndef MVVM_BASIC_APISERVICE_H
#define MVVM_BASIC_APISERVICE_H


class APIService {
    virtual void getList() = 0;
};

class APIServiceImpl: APIService {
    void getList();
};


#endif //MVVM_BASIC_APISERVICE_H
