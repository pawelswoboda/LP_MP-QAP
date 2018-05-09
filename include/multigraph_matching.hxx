#ifndef LP_MP_MULTIGRAPH_MATCHING_H
#define LP_MP_MULTIGRAPH_MATCHING_H

namespace LP_MP {

struct FMC_MGM { // factor message connection
   constexpr static const char* name = "multigraph matching";
      
   using UnaryFactor = FactorContainer<UnarySimplexFactor, FMC_MGM, 0>;
   using PairwiseFactor = FactorContainer<PairwiseSimplexFactor, FMC_MGM, 1>;
   using triplet_consistency_factor = FactorContainer<multigraph_matching_triplet_consistency_factor, FMC_MGM, 2>; 
   using FactorList = meta::list< UnaryFactor, PairwiseFactor, triplet_consistency_factor>;

   using EqualityMessageType = EqualityMessage<PairwiseConstruction::BothSides>;
   using AssignmentConstraintMessage = MessageContainer<EqualityMessageType, 0, 0, message_passing_schedule::full, variableMessageNumber, variableMessageNumber, FMC_MGM, 0 >;
   using UnaryPairwiseMessageLeftContainer = MessageContainer<UnaryPairwiseMessage<Chirality::left,false>, 0, 1, message_passing_schedule::left, variableMessageNumber, 1, FMC_MGM, 1 >;
   using UnaryPairwiseMessageRightContainer = MessageContainer<UnaryPairwiseMessage<Chirality::right,false>, 0, 1, message_passing_schedule::left, variableMessageNumber, 1, FMC_MGM, 2 >;

   using scalar_triplet_consistency_message_container = MessageContainer<simplex_multigraph_matching_triplet_scalar_consistency_message, 0, 2, message_passing_schedule::left, variableMessageNumber, 1, FMC_MGM, 3 >;
   using x_vector_triplet_consistency_message_container = MessageContainer<simplex_multigraph_matching_triplet_vector_consistency_message<Chirality::left>, 0, 2, message_passing_schedule::left, variableMessageNumber, 1, FMC_MGM, 4>; 
   using y_vector_triplet_consistency_message_container = MessageContainer<simplex_multigraph_matching_triplet_vector_consistency_message<Chirality::right>, 0, 2, message_passing_schedule::left, variableMessageNumber, 1, FMC_MGM, 5>; 


   using MessageList = meta::list< AssignmentConstraintMessage, UnaryPairwiseMessageLeftContainer, UnaryPairwiseMessageRightContainer, 
         scalar_triplet_consistency_message_container, x_vector_triplet_consistency_message_container, y_vector_triplet_consistency_message_container >;

   using mrf = AssignmentGmConstructor<StandardMrfConstructor<FMC_MGM,0,1,1,2>>;
   using mrfLeft = mrf;
   using mrfRight = disable_write_constructor<mrf>;
   using ProblemDecompositionList = meta::list<mrfLeft, mrfRight>;
};

}

#endif // LP_MP_MULTIGRAPH_MATCHING_H
