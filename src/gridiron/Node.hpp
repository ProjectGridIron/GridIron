#ifndef GRIDIRON_NODE_HPP
#define GRIDIRON_NODE_HPP

#include <htmlcxx2/htmlcxx2_html.hpp>
#include <htmlcxx2/kp_tree.hh>

namespace GridIron {
    namespace Properties {
        class AttributeMappedProperty;
        class ContentMappedProperty;
        class ComparedAttributeProperty;
    }

    class Node : public htmlcxx2::HTML::Node {
        friend GridIron::Properties::AttributeMappedProperty;
        friend GridIron::Properties::ContentMappedProperty;
        friend GridIron::Properties::ComparedAttributeProperty;
    public:
            /**
             * Expose the protected addAttribute, returns whether call succeeded
             * @param key
             * @param value
             * @return
             */
        inline bool newAttribute(const std::string &key, const std::string &value) {
            if (this->hasAttribute(key)) {
                return false;
            }
            // call parent
            htmlcxx2::HTML::Node::addAttribute(key, value);
            return true;
        }

        inline const std::string getAttribute(const std::string &key) const {
            std::string value;
            attribute(key, value);
            return value;
        }

        inline bool updateAttribute(const std::string &key, const std::string &value) {
            for (size_t i = 0, l = attributeKeys_.size(); i < l; ++i)
            {
                if (htmlcxx2::HTML::impl::icompare(attributeKeys_[i].c_str(), key.c_str()) == 0)
                {
                    attributeValues_[i] = value;
                    return true;
                }
            }
            // not found, try to add
            return newAttribute(key, value);
        }

        inline bool deleteAttribute(const std::string &key) {
            for (size_t i = 0, l = attributeKeys_.size(); i < l; ++i)
            {
                if (htmlcxx2::HTML::impl::icompare(attributeKeys_[i].c_str(), key.c_str()) == 0)
                {
                    attributeValues_.erase(attributeValues_.begin() + i);
                    attributeKeys_.erase(attributeKeys_.begin() + i);
                    return true;
                }
            }
            return false;
        }

        inline void updateText(const std::string &text) {
            text_ = text;
        }
    };
}

#endif //GRIDIRON_NODE_HPP
