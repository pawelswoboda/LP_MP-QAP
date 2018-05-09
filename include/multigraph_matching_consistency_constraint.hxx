#ifndef LP_MP_MULTIGRAPH_MATCHING_CONSISTENCY_CONSTRAINT_HXX
#define LP_MP_MULTIGRAPH_MATCHING_CONSISTENCY_CONSTRAINT_HXX

namespace LP_MP {

// Z_ij = \sum_p X_ip Y_pj
class multigraph_matching_triplet_consistency_factor {
public:
    // cost vectors
    REAL cost_z;
    vector<REAL> cost_x;
    vector<REAL> cost_y;

    // primal
    std::size_t x, y;

    multigraph_matching_triplet_consistency_factor(const std::size_t dim)
    : cost_z(0.0),
    cost_x(dim, 0.0),
    cost_z(dim, 0.0)
    {
        assert(dim > 1);
    }

    template<typename ITERATOR>
    std::array<std::size_t, 2> min_indices(ITERATOR begin, ITERATOR end)
    {
        REAL smallest_taken = std::numeric_limits<REAL>::infinity();
        REAL second_smallest_taken = std::numeric_limits<REAL>::infinity();
        std::size_t min_idx, second_min_idx;
        for(auto it=begin; it!=end; ++it) {
            ...

        } 
        return {min_idx, second_min_idx};
    }

    REAL EvaluatePrimal() const
    {
        if(x > cost_x.size() || y > cost_y.size()) { return std::numeric_limits<REAL>::infinity(); }
        else if(x == y) { return cost_z + cost_x[x] + cost_y[y]; }
        else { return cost_x[x] + cost_y[y]; }
    }

    std::tuple<std::size_t, std::size_t, REAL> optimize() const
    {
        // case z = 0
        auto x_min_idx = min_indices(cost_x.begin(), cost_x.end());
        auto y_min_idx = min_indices(cost_y.begin(), cost_y.end());
        std::size_t x_diff, y_diff;
        REAL cost_0;
        if(x_min_idx[0] != y_min_idx[0]) {
             cost_0 = cost_x[ x_min_idx[0] ] + cost_y[ y_min_idx[0] ];
             x = x_min_idx[0];
             y = y_min_idx[0]; 
        } else {
             if( cost_x[ x_min_idx[0] ] + cost_y[ y_min_idx[1] ] < cost_x[ x_min_idx[1] ] + cost_y[ y_min_idx[0] ] ) {
                 cost_0 = cost_x[ x_min_idx[0] ] + cost_y[ y_min_idx[1] ];
                 x = x_min_idx[0];
                 y = y_min_idx[1];
             } else {
                 cost_0 = cost_x[ x_min_idx[1] ] + cost_y[ y_min_idx[0] ];
                 x = x_min_idx[1];
                 y = y_min_idx[0];
             }
        }

        // case z = 1
        REAL min_same_component = std::numeric_limits<REAL>::infinity();
        std::size_t x_same, y_same;
        for(std::size_t i=0; i<cost_x.size(); ++i) {
            if(cost_x[i] + cost_y[i] < min_same_component) {
                min_same_component = cost_x[i] + cost_y[i];
                x_same = i;
                y_same = i; 
            }
        }
        REAL cost_1 = cost_z + min_same_component;

        if(cost_0 < cost_1) { return {x_diff, y_diff, cost_0}; }
        else { return {x_same, y_same, cost_1}; }
    }

    REAL LowerBound() const
    {
        return std::get<2>(optimize());
    }

    void MaximizePotentialAndComputePrimal() 
    {
        auto result = optimize();
        x = std::get<0>(result);
        y = std::get<1>(result);
    }
    

   template<class ARCHIVE> void serialize_primal(ARCHIVE& ar) { ar(x,y); }
   template<class ARCHIVE> void serialize_dual(ARCHIVE& ar) { ar( cost_z, cost_x, cost_y ); }

   auto export_variables() { return std::tie(cost_z, cost_y, cost_y); }

   void init_primal() { x = std::numeric_limits<std::size_t>::max(); y = std::numeric_limits<std::size_t>::max(); }

   template<typename EXTERNAL_SOLVER>
   void construct_constraints(EXTERNAL_SOLVER& s, typename EXTERNAL_SOLVER::scalar z, typename EXTERNAL_SOLVER::vector x, typename EXTERNAL_SOLVER::vector y) const
   {
   }
   template<typename EXTERNAL_SOLVER>
   void convert_primal(EXTERNAL_SOLVER& s, typename EXTERNAL_SOLVER::scalar z, typename EXTERNAL_SOLVER::vector x, typename EXTERNAL_SOLVER::vector y) const
   {
   }
};

class simplex_multigraph_matching_triplet_scalar_consistency_message {

};

// left factor: simplex factor
// right factor multigraph_matching_triplet_consistency_factor
template<Chirality C> // does the message connect to x (left) or y (right) variable
class simplex_multigraph_matching_triplet_vector_consistency_message {
public:
   template<typename LEFT_FACTOR, typename MSG>
   void RepamLeft(LEFT_FACTOR& l, MSG& msg)
   {
      for(std::size_t i=0; i<l.size(); ++i) {
          l[i] += msg[i];
      }
   }

   template<typename RIGHT_FACTOR, typename MSG>
   void RepamRight(RIGHT_FACTOR& r, MSG& msg)
   {
       if(C == Chirality::left) {
           assert(msg.size() == r.cost_x.size());
           for(std::size_t i=0; i<r.cost_x.size(); ++i) {
               r.cost_x[i] += msg[i]; 
           }
       } else {
           assert(msg.size() == r.cost_y.size());
           for(std::size_t i=0; i<r.cost_y.size(); ++i) {
               r.cost_y[i] += msg[i]; 
           } 
       }
   }
   
    template<typename LEFT_FACTOR, typename MSG>
    void send_message_to_right(const LEFT_FACTOR& l, MSG& msg, const REAL omega = 1.0)
    {
        const auto min = l.min();
        vector<REAL> m(l.size());
    }

    template<typename RIGHT_FACTOR, typename MSG>
    void send_message_to_left(const RIGHT_FACTOR& r, MSG& msg, const REAL omega = 1.0)
    {

    }
   


}

} // namespace LP_MP

#endif // LP_MP_MULTIGRAPH_MATCHING_CONSISTENCY_CONSTRAINT_HXX
