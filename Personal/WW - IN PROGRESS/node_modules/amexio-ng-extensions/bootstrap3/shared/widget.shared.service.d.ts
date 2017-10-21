/**
 * A Shared Service class, used mainly for Form Validations And Notification Feedback
 */
export declare class WidgetService {
    constructor();
    /**
     * Sets the the form field to disabled mode.
     * @param inputTexts Reference to Form Components
     * @param fieldName Name of the Field
     * @param disabled  Boolean, Set true | false to disable
     */
    setDisabled(inputTexts: any, fieldName: string, disabled: boolean): void;
    validate(inputTexts: any): boolean;
    validateAll(inputTexts: any[]): boolean;
    toasterDanger(title: string, message: string, timeout: string): void;
    toasterSuccess(title: string, message: string, timeout: string): void;
    toasterInfo(title: string, message: string, timeout: string): void;
}
