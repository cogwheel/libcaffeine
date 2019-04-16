#pragma once

#include "Api.hpp"
#include "nlohmann/json.hpp"

//// C datatype serialization has to be outside of caff namespace
//// TODO: don't pass ownership of these to C-side

NLOHMANN_JSON_SERIALIZE_ENUM(caff_ConnectionQuality, {
    {caff_ConnectionQualityGood, "GOOD"},
    {caff_ConnectionQualityPoor, "POOR"},
    {caff_ConnectionQualityUnknown, nullptr},
    })

namespace nlohmann {
    template <typename T>
    struct adl_serializer<caff::optional<T>> {
        static void to_json(json& json, const caff::optional<T>& opt) {
            if (opt.has_value()) {
                json = *opt;
            }
            else {
                json = nullptr;
            }
        }

        static void from_json(const json& json, caff::optional<T>& opt) {
            if (json.is_null()) {
                opt.reset();
            }
            else {
                opt = json.get<T>();
            }
        }
    };
}

namespace caff {
    using Json = nlohmann::json;

    template <typename ValueT, typename KeyT>
    inline void get_value_to(Json const & json, KeyT key, ValueT & target)
    {
        json.at(key).get_to(target);
    }

    template <typename ValueT>
    inline void get_value_to(Json const & json, char const * key, optional<ValueT> & target)
    {
        auto it = json.find(key);
        if (it != json.end()) {
            it->get_to(target);
        }
        else {
            target.reset();
        }
    }

    template <typename T>
    inline void set_value_from(Json & json, char const * key, T const & source)
    {
        json[key] = source;
    }

    template <typename T>
    inline void set_value_from(Json & json, char const * key, optional<T> const & source)
    {
        if (source) {
            json[key] = *source;
            return;
        }
        auto it = json.find(key);
        if (it != json.end()) {
            json.erase(it);
        }
    }

    NLOHMANN_JSON_SERIALIZE_ENUM(ContentType, {
        {ContentType::Game, "game"},
        {ContentType::User, "user"},
        })

    void from_json(Json const & json, Credentials & credentials);

    void from_json(Json const & json, UserInfo & userInfo);

    void from_json(Json const & json, GameInfo & gameInfo);

    void from_json(Json const & json, GameList & games);

    void to_json(Json & json, IceInfo const & iceInfo);

    void to_json(Json & json, Client const & client);

    void to_json(Json & json, FeedCapabilities const & capabilities);
    void from_json(Json const & json, FeedCapabilities & capabilities);

    void to_json(Json & json, FeedContent const & content);
    void from_json(Json const & json, FeedContent & content);

    void to_json(Json & json, FeedStream const & stream);
    void from_json(Json const & json, FeedStream & stream);

    void to_json(Json & json, Feed const & feed);
    void from_json(Json const & json, Feed & feed);

    void to_json(Json & json, Stage const & stage);
    void from_json(Json const & json, Stage & stage);

    void to_json(Json & json, StageRequest const & request);

    void from_json(Json const & json, StageResponse & response);

    void from_json(Json const & json, HeartbeatResponse & response);

    void from_json(Json const & json, DisplayMessage & message);

    void from_json(Json const & json, FailureResponse & response);
}
