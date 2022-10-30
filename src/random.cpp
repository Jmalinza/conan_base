#include <boost/random.hpp>

#include "random.h"

double math::random(const double mean, const double std_deviation){
    boost::mt19937 rng;
    auto normal_dist = boost::random::normal_distribution<double>(mean, std_deviation);    
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > random_generator(rng, normal_dist);    
    return random_generator();
}