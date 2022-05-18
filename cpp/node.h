#ifndef NODE_HEADER_H
#define NODE_HEADER_H
#include <vector>
class Connection;
class Node {
public:
    long int number; // number of the node
    long int layer; // layer of the node
    int activationFunctionIndex; // index of the activation function
    long double bias; // bias of the node
    bool output; // is the node an output node
    long double inputSum; // sum of the input
    long double outputValue; // output value of the node
    std::vector<Connection*> outputConnections; // vector of output connections of the node, !! do not delete it in destruction !!
    //
    // methods
    /**
     * @brief Construct a new Node object
     *
     * @param _number number of the node
     * @param _layer layer of the node
     * @param _isOutput is the node an output node
     *
     */
    Node(long int _number, long int _layer, bool _isOutput = false);
    //
    /**
     * @brief Destroy the Node object, ONLY called by the genome object
     *
     */
    ~Node();
    //
    /**
     * @brief pass down the calculated output value
     *
     */
    void engage();
    // 
    /**
     * @brief randomly mutate the bias of this node
     *
     */
    void mutateBias();
    //
    /**
     * @brief randomly mutate a new activation function
     *
     */
    void mutateActivationFunction();
    //
    /**
     * @brief check this and node is connected
     * @param node node to check
     * @return true if connected, false if not connected
     *
     */
    bool isConnected(const Node* node) const;
    //
    /**
     * @brief return a deep copy of this node
     * @return Node
     *
     */
    Node* clone() const;
    //
    /**
     * @brief return activation function
     * @return auto activation function
     * ? https://stackoverflow.com/questions/31387238/c-function-returning-function
     */
    auto activation();
};
#endif