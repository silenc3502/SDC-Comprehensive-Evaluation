//
// Created by eddi on 23. 12. 15.
//

#include "RailGunServiceImpl.h"
#include "../../uniformAccelerationMotion/service/UniformAccelerationMotionServiceImpl.h"

#include <iostream>
#include <iomanip>

RailGunServiceImpl RailGunServiceImpl::instance(nullptr);

RailGunServiceImpl::RailGunServiceImpl(
        std::unique_ptr<RailGunRepository> repository)
            : railGunRepository(std::move(repository)) {}

RailGunServiceImpl& RailGunServiceImpl::getInstance(std::unique_ptr<RailGunRepository> repository) {
    if (!instance.railGunRepository) {
        instance.railGunRepository = std::move(repository);
    }
    return instance;
}

RailGunServiceImpl& RailGunServiceImpl::getInstance() {
    return instance;
}

void RailGunServiceImpl::fire() {
    std::cout << "Service: Fire!" << std::endl;

    UniformAccelerationMotionServiceImpl& uniformAccelerationMotionService = UniformAccelerationMotionServiceImpl::getInstance();
    double timeToReachTerminalVelocity = uniformAccelerationMotionService.calculateTime(100, 125000000000);
    std::cout << "탄환 가속에 소요된 시간: " << std::fixed << std::setprecision(5)
            << timeToReachTerminalVelocity << std::endl;

    //UniformVelocityMotionServiceImpl& uniformVelocityMotionService;

    railGunRepository->fire();
}
