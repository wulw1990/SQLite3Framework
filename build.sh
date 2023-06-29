xcodebuild archive \
    -project SQLite3Framework.xcodeproj \
    -scheme SQLite3Framework \
    -destination "generic/platform=macOS" \
    -archivePath "build/SQLite3Framework" 

xcodebuild -create-xcframework\
 -archive build/SQLite3Framework.xcarchive -framework SQLite3Framework.framework\
 -output build/SQLite3Framework.xcframework
